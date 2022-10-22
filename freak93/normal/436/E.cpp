#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, W; cin >> N >> W;

    vector<int> first(N), second(N), comb(N);
    for (int i = 0; i < N; ++i) {
        cin >> first[i] >> comb[i];
        second[i] = comb[i] - first[i];
    }

    set< pair<int, int> > A, B, C;
    A.insert(make_pair(numeric_limits<int>::max(), -1));
    B.insert(make_pair(numeric_limits<int>::max(), -1));
    C.insert(make_pair(numeric_limits<int>::max(), -1));

    for (int i = 0; i < N; ++i) {
        A.insert(make_pair(first[i], i));
        C.insert(make_pair(comb[i], i));
    }

    int64_t answer = 0;
    vector<int> taken(N, 0);
    for (int i = 1; i <= W; ++i) {
        auto take1 = *A.begin();
        int from1 = 0;
        if (*B.begin() < take1)
            take1 = *B.begin(), from1 = 1;
        auto best2 = *C.begin();

        if (from1)
            B.erase(B.begin());
        else {
            A.erase(A.begin());
            B.insert(make_pair(second[take1.second], take1.second));
            C.erase(make_pair(comb[take1.second], take1.second));
        }

        if (i == W) {
            answer += take1.first;
            if (from1)
                taken[take1.second] |= 2;
            else
                taken[take1.second] |= 1;
            break;
        }

        auto take2 = *A.begin();
        int from2 = 0;
        if (*B.begin() < take2)
            take2 = *B.begin(), from2 = 1;

        if (from2)
            B.erase(B.begin());
        else {
            A.erase(A.begin());
            B.insert(make_pair(second[take2.second], take2.second));
            C.erase(make_pair(comb[take2.second], take2.second));
        }

        if (take1.first + take2.first > best2.first) { // retreat, houston, retreat
            if (from2)
                B.insert(take2);
            else {
                A.insert(take2);
                B.erase(make_pair(second[take2.second], take2.second));
                C.insert(make_pair(comb[take2.second], take2.second));
            }

            if (from1)
                B.insert(take1);
            else {
                A.insert(take1);
                B.erase(make_pair(second[take1.second], take1.second));
                C.insert(make_pair(comb[take1.second], take1.second));
            }


            answer += best2.first;
            taken[best2.second] |= 3;
            A.erase(make_pair(first[best2.second], best2.second));
            C.erase(best2);
            ++i;
        } else {
            if (from1)
                taken[take1.second] |= 2;
            else
                taken[take1.second] |= 1;

            if (from2)
                B.insert(take2);
            else {
                A.insert(take2);
                B.erase(make_pair(second[take2.second], take2.second));
                C.insert(make_pair(comb[take2.second], take2.second));
            }

            answer += take1.first;
        }
    }

    cout << answer << "\n";
    for (int i = 0; i < N; ++i)
        if (taken[i] == 3)
            cout << '2';
        else
            cout << taken[i];
    cout << "\n";
}