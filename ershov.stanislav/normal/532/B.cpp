#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 200200;

int n, a[N];
vector<int> tree[N];

pair<ll, ll> dfs(int v) {
    pair<ll, ll> ans = mp(0ll, (ll) -1e14);
    for (auto i : tree[v]) {
        pair<ll, ll> c = dfs(i);
        pair<ll, ll> a = mp(max(ans.fs + c.fs, ans.sc + c.sc), max(ans.fs + c.sc, ans.sc + c.fs));
        a.fs = max(a.fs, (ll) -1e14);
        a.sc = max(a.sc, (ll) -1e14);
        ans = a;
    }
    pair<ll, ll> res = mp(ans.fs, max(ans.sc, ans.fs + a[v]));
    return res;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d%d", &p, &a[i]);
        if (p != -1) tree[p].pb(i);
    }
    pair<ll, ll> res = dfs(1);
    cout << max(res.fs, res.sc) << endl;
    return 0;
}