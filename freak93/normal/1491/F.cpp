#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int fixed, int from, int to, int sure) {
    if (from > to)
        return -1;

    if (from == to && sure)
        return from;

    int mid = (from + to) / 2;
    cout << "? 1 " << mid - from + 1 << "\n";
    cout << fixed << "\n";
    for (int i = from; i <= mid; ++i)
        cout << i << " ";
    cout << "\n";
    int F; cin >> F;
    if (F == 0)
        return find(fixed, mid + 1, to, sure);
    else 
        return find(fixed, from, mid, 1);
}

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int where = -1;
        for (int i = N - 1; i >= 1; --i) {
            cout << "? 1 " << N - i << "\n";
            cout << i << "\n";
            for (int j = i + 1; j <= N; ++j)
                cout << j << " ";
            cout << "\n";
            cout.flush();

            int F; cin >> F;
            if (F != 0) {
                where = i;
                break;
            }
        }

        vector<int> answer;
        for (int i = 1; i < where; ++i) {
            if (i == N && where == N - 1)
                continue;
            cout << "? 1 1\n" << where << "\n" << i << "\n";
            cout.flush();
            int F; cin >> F;
            if (F == 0)
                answer.push_back(i);
        }
        auto x = find(where, where + 1, N, 1);
        for (int i = where + 1; i <= N; ++i)
            if (i != x)
                answer.push_back(i);

        cout << "! " << answer.size() << " ";
        for (auto &x : answer)
            cout << x << " ";
        cout << "\n";
        cout.flush();
    }
}