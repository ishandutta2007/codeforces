#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

vector<int> d[maxn];
int f[maxn];

void add(int x, int n) {
    for (int i = x; i <= n; i += i & (-i)) f[i]++;
}

int qry(int x) {
    int v = 0;
    for (int i = x; i > 0; i -= i & (-i)) v += f[i];
    return v;
}

void solve()
{
    LL ans = 0;
    int n, x, l, r;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        d[x].push_back(i);
    }

    l = 0, r = n;
    for (int i = n; i > 0; i--) {
        if (d[i].empty()) continue;
        for (auto e:d[i]) add(e, n);
        r = min(r, d[i][0] - 1);
        l = max(l, d[i].back());
        swap(l, r);
        ans += qry(r) - qry(l);
    }

    cout << ans << endl;
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}