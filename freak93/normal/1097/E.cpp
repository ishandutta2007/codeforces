#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            --A[i];
        }

        vector<int> prev(N, -1), from(N, -1);
        vector< vector<int> > answer;
        while (!A.empty()) {
            vector<int> lis;
            for (auto &x : A) {
                auto it = lower_bound(lis.begin(), lis.end(), x);
                int i = it - lis.begin();
                if (i > 0)
                    from[x] = lis[i - 1];
                else 
                    from[x] = -1;
                if (it == lis.end()) {
                    lis.push_back(x);
                    prev[x] = -1;
                } else {
                    prev[x] = *it;
                    *it = x;
                }
            }

            auto K = lis.size();

            if (K * (K + 1) / 2 > A.size()) {
                vector<int> aux;
                for (int i = lis.back(); i != -1; i = from[i])
                    aux.push_back(i);
                reverse(aux.begin(), aux.end());

                for (int i = 0, j = 0, k = 0; i < int(A.size()); ++i)
                    if (j < int(K) && A[i] == aux[j])
                        ++j;
                    else 
                        A[k++] = A[i];
                A.resize(A.size() - lis.size());
                answer.push_back(aux);
                continue;
            }
            for (auto &head : lis) {
                vector<int> aux;
                for (int i = head; i != -1; i = prev[i])
                    aux.push_back(i);
                reverse(aux.begin(), aux.end());
                answer.push_back(aux);
            }
            A.clear();
        }

        cout << answer.size() << "\n";
        for (auto &line : answer) {
            cout << line.size() << " ";
            for (auto &x : line)
                cout << x + 1 << " ";
            cout << "\n";
        }
    }
}