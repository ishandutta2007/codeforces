#include <bits/stdc++.h>

#define int ll
#define fi first
#define se second
#define init int n; cin >> n;
#define iniit int n, m; cin >> n >> m;
#define itn int
#define ld long double
#define ll long long
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

using namespace std;

int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}

void ct(vpii &a) {
    for (auto &i: a) cout << i.fi << ":" << i.se << ' ';
    cout << '\n';
}

void ct(vvpii &a) {
    for (auto &i: a) ct(i);
}

void ct(vector<vector<int>> &a) {
    for(auto &i: a) ct(i);
}

void ct(vector<set<int>> &a) {
    for(auto &i: a) {
        for(auto &j: i) cout << j << ' ';
        cout << '\n';
    }
}

void ct(set<pii> &a) {
    for(auto &i: a) cout << i.first << ':' << i.second << ' ';
    cout << '\n';
}

void ct(pii &a) {
    cout << a.first << ':' << a.second << '\n';
}

void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void ci(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); ++i) ci(a[i]);
}

void dfs(vi &used, vi &comp, int v, vvi &g) {
    used[v] = 1;
    comp.pb(v);
    for(auto i: g[v]) {
        if(!used[i]) dfs(used, comp, i, g);
    }
}

signed main() {
    iniit;
    vvi g(n, vi(0));
    fr(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vvi comp;
    vi used(n);
    fr(i, n) {
        if (!used[i]) {
            vi o;
            comp.pb(o);
            dfs(used, comp[comp.size() - 1], i, g);
        }
    }
    for(auto &i: comp) sort(all(i));
    vpii a;
    int s = comp.size();
    fr(i, s) {
        a.pb(mp(comp[i][0], comp[i][comp[i].size() - 1]));
    }
    //ct(comp);
    //ct(a);
    sort(all(a));
    int mx = 0;
    int ans = 0;
    for(int i = 0; i < s; ++i) {
        if (mx > a[i].fi) {
            ++ans;
        }
        mx = max(mx, a[i].se);
    }
    cout << ans;
}