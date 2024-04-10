#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int mod = 998244353;
const int maxn = 5e5 + 5;

int a[maxn], dp[maxn], f[maxn];
LL s[maxn];
unordered_map<LL, int> g;
vector<LL> d;

void add(int x, int n, int v)
{
    for (int i = x; i <= n; i += i & (-i)) f[i] = max(f[i], v);
}

int qry(LL x)
{
    int w = -mod;
    for (int i = x - 1; i > 0; i -= i & (-i)) w = max(w, f[i]);
    return w;
}

int getIdx(LL x)
{
    return lower_bound(d.begin(), d.end(), x) - d.begin() + 1;
}

void solve()
{
    int n;
    LL base = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) f[i] = -mod;

    d.clear();
    s[0] = 0;
    d.push_back(0);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        d.push_back(s[i]);
    }

    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    g.clear();
    g[s[0]] = 0;
    add(getIdx(s[0]), d.size(), 0);
    for (int i = 1; i <= n; i++) {
        int j = getIdx(s[i]);
        if (a[i] < 0) dp[i] = dp[i - 1] - 1;
        else if (a[i] == 0) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + 1;

        if (g.find(s[i]) != g.end()) {
            dp[i] = max(dp[i], g[s[i]]);
        }

        dp[i] = max(dp[i], qry(j) + i);

        //cout << i << ": " <<s[i]<<" "<< dp[i] << " " << qry(s[i]) << " " << g[s[i]] << endl;

        if (g.find(s[i]) != g.end()) g[s[i]] = max(g[s[i]], dp[i]);
        else g[s[i]] = dp[i];
        //cout<<"==" << s[i]<<endl;
        add(j, d.size(), dp[i] - i);
    }

    cout << dp[n] << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}