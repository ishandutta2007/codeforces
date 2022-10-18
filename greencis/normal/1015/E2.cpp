#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

set<int> su[1005], sl[1005], sd[1005], sr[1005];
int n, m;
char s[1005][1005], t[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        sr[i].insert(m + 1);
        sl[i].insert(0);
    }
    for (int j = 1; j <= m; ++j) {
        sd[j].insert(n + 1);
        su[j].insert(0);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
        for (int j = 1; j <= m; ++j) {
            t[i][j] = '.';
            if (s[i][j] == '.') {
                sr[i].insert(j);
                sl[i].insert(-j);
                sd[j].insert(i);
                su[j].insert(-i);
            }
        }
    }
    vector<vector<int>> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*') {
                int dist = *sr[i].lower_bound(j) - j;
                dist = min(dist, j + *sl[i].lower_bound(-j));
                dist = min(dist, *sd[j].lower_bound(i) - i);
                dist = min(dist, i + *su[j].lower_bound(-i));
                if (dist > 1) {
                    ans.push_back({i, j, dist - 1});
                    for (int z = 0; z <= dist - 1; ++z)
                        t[i][j + z] = t[i][j - z] = t[i - z][j] = t[i + z][j] = '*';
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (strcmp(t[i] + 1, s[i] + 1)) {
            cout << -1;
            return-0;
        }
    }
    cout << ans.size() << "\n";
    for (auto& x : ans)
        cout << x[0] << " " << x[1] << " " << x[2] << "\n";
}