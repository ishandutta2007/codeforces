#include <bits/stdc++.h>

using namespace std;

using P = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    set<int, greater<int>> yet;
    vector<int> dist(n + 1, n);
    vector<P> par(n + 1);
    queue<int> q;
    for (int i = n - 1; i >= 0; i--) yet.emplace_hint(yet.end(), i);
    dist[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int i = q.front();
        q.pop();

        decltype(yet.begin()) it;
        while (*(it = yet.lower_bound(i)) >= i - a[i]) {
            if (*it == 0) {
                vector<int> ans{0};
                for (; i != n; i = par[i].first) {
                    ans.push_back(par[i].second);
                }

                int m = ans.size();
                cout << m << '\n';
                for (int p = m - 1; p >= 0; p--) {
                    cout << ans[p] << " \n"[p == 0];
                }
                return 0;
            }

            int j = *it + b[*it];
            if (dist[j] == n) {
                dist[j] = dist[i] + 1;
                par[j] = {i, *it};
                q.push(j);
            }

            yet.erase(it);
        }
    }

    cout << "-1\n";
}