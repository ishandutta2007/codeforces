#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n, m;
int a[200010];
int l[200010];
int r[200010];
int nxt[200010];
vector<int> g[200010];
vector<int> rg[200010];

void solve() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> l[i] >> r[i];
    for(int i=1; i<=n; i++) g[i].clear(), rg[i].clear(), nxt[i] = 0;

    map<int,vector<int>> M;
    for(int i=1; i<=n; i++) {
        if(M.find(a[i]) != M.end()) nxt[M[a[i]].back()] = i;
        M[a[i]].eb(i);
    }

    for(int i=1; i<=m; i++) {
        g[l[i]].eb(r[i]);
        rg[r[i]].eb(l[i]);
    }

    set<int> S;
    int lb = inf, ub = -inf;
    vector<pii> v;
    for(int i=1; i<=n; i++) {
        for(auto j : g[i]) {
            S.insert(j);
        }

        if(nxt[i] && S.lower_bound(nxt[i]) != S.end()) lb = min(lb, nxt[i]), ub = max(ub, i);
        if(S.lower_bound(i) == S.end()) continue;
        
        int ed = *prev(S.end());
        int pos = upper_bound(all(M[a[i]]), ed) - M[a[i]].begin() - 1;
        if(M[a[i]][pos] == i) continue;

        v.eb(i, M[a[i]][pos]);
    }

    S.clear();
    for(int i=n; i>=1; i--) {
        for(auto j : rg[i]) {
            S.insert(j);
        }

        if(S.upper_bound(i) == S.begin()) continue;
        int ed = *S.begin();
        int pos = lower_bound(all(M[a[i]]), ed) - M[a[i]].begin();
        if(M[a[i]][pos] == i) continue;

        v.eb(M[a[i]][pos], i);
    }

    sort(all(v));

    int mx = ub, ans = inf;
    for(auto i : v) {
        if(i.fi > lb) break;
        ans = min(ans, mx - i.fi + 1);
        mx = max(mx, i.se);
    }
    ans = min(ans, mx - lb+1);
    ans = max(ans, 0);

    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}