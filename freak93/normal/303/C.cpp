#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> V(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];
    sort(V.begin(), V.end());

    vector< vector<int> > bad(V.back() + 1);

    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j) {
            int v = V[j] - V[i];
            if (!bad[v].size() or bad[v].back() != i)
                if (int(bad[v].size()) <= K + 1)
                    bad[v].push_back(i);
        }

    vector<int> last(V.back() + 1, 0);
    for (int i = 1; i <= V.back(); ++i) {
        int total = 0;
        for (int j = 0; j < int(bad.size()); j += i) {
            for (auto &x : bad[j]) {
                if (last[x] != i) {
                    ++total;
                    last[x] = i;
                }
            }

            if (total > K)
                break;
        }

        if (total <= K) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << V.back() + 1 << "\n";
}