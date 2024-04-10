#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 5005;
vector<int> adj[maxn];
int v[maxn], r[maxn], b[maxn];
bool c[maxn], dp[maxn][maxn], res[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y); adj[y].pb(x);
    }
    fill(v, v+n, -1);
    int t = -1;
    for (int i = 0; i < n; i++)
        if (v[i] == -1) {
            vector<int> s = {i};
            v[i] = ++t;
            r[t] = 1; b[t] = 0;
            while (!s.empty()) {
                int j = s.back(); s.pop_back();
                for (auto& k : adj[j]) {
                    if (v[k] == -1) {
                        s.pb(k);
                        v[k] = t;
                        c[k] = !c[j];
                        if (c[k]) b[t]++;
                        else r[t]++;
                    } else if (c[k] == c[j]) {
                        cout << "NO\n"; return 0;
                    }
                }
            }
        }
    for (int i = 0; i <= t; i++)
        for (int j = 0; j <= n2; j++) {
            int k = abs(r[i]-b[i]);
            dp[i][j] = (i == 0 ? j == 0 : dp[i-1][j]) || (i == 0 ? j == k : k <= j && dp[i-1][j-k]);
        }
    for (int i = 0; i <= t; i++)
        n2 -= min(r[i], b[i]);
    if (!dp[t][n2]) {
        cout << "NO\n"; return 0;
    }
    for (int i = t; i >= 0; i--) {
        int k = abs(r[i]-b[i]);
        if ((i == 0 && k == n2) || (k <= n2 && dp[i-1][n2-k])) {
            res[i] = r[i] < b[i]; n2 -= k;
        } else
            res[i] = r[i] > b[i];
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (c[i] == res[v[i]])
            cout << 2;
        else {
            cout << (n1-- > 0 ? 1 : 3);
        }
    }
    cout << "\n";
}