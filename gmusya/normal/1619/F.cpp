#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int sz1 = n / m;
        int sz2 = sz1 + 1;
        int cnt2 = n % m;
        int cnt1 = m - cnt2;
        vector<vector<vector<int>>> schedule(k, vector<vector<int>>(m));
        for (int game = 0; game < k; ++game) {
            int first = game * sz1 * cnt1;
            for (int table = 0; table < cnt1; ++table) {
                for (int player = first + table * sz1; player < first + table * sz1 + sz1; ++player) {
                    schedule[game][table].push_back(player % n);
                }
            }
            for (int table = 0; table < cnt2; ++table) {
                for (int player = first + cnt1 * sz1 + table * sz2; player < first + cnt1 * sz1 + table * sz2 + sz2; ++player) {
                    schedule[game][table + cnt1].push_back(player % n);
                }
            }
        }
        for (int game = 0; game < k; ++game) {
            for (int table = 0; table < m; ++table) {
                cout << schedule[game][table].size() << ' ';
                for (auto& now : schedule[game][table]) {
                    cout << now + 1 << ' ';
                }
                cout << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}