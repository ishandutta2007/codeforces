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
typedef pair<LL, int> PL;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

struct BT {
    LL f[maxn];
    void addR(int x, int n, LL v) {
        for (int i = x; i <= n; i += i & (-i)) f[i] += v;
    }

    LL sumL(int x, int n) {
        LL res = 0;
        for (int i = x; i > 0; i -= i & (-i)) res += f[i];
        return res % mod;
    }
} f[2];

int a[maxn], b[maxn], w[maxn], idx[maxn];
LL p[maxn], ans[maxn];
vector<P> qry[maxn];

void solve()
{
    int n, q, l, r;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i < n; i++) w[i] = a[i + 1] - a[i];

    vector<LL> tr;
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + b[i];
    for (int i = 0; i <= n; i++) tr.push_back(p[i]);
    tr.push_back(0);
    sort(tr.begin(), tr.end());
    tr.erase(unique(tr.begin(), tr.end()), tr.end());
    int m = tr.size();

    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        qry[l].push_back(P(l - 1, -i));
        qry[r].push_back(P(l - 1, i));
    }

    LL sumw = 0, sumwp = 0, sl, sr, wl, wr, tmp;
    idx[0] = lower_bound(tr.begin(), tr.end(), 0) - tr.begin() + 1;
    for (int i = 1; i <= n; i++) {

        for (auto e:qry[i]) {
            l = idx[e.fi];
            wl = f[0].sumL(l - 1, m);
            wr = sumwp - wl;
            sl = f[1].sumL(l - 1, m);
            sr = sumw - sl;

            tmp = wr - p[e.fi] % mod * sr % mod;
            tmp += p[e.fi] % mod * sl % mod - wl;
            tmp = (tmp % mod + mod) % mod;
            if (e.se > 0) ans[e.se] += tmp;
            else ans[-e.se] += mod - tmp;
        }

        idx[i] = lower_bound(tr.begin(), tr.end(), p[i]) - tr.begin() + 1;
        sumw += w[i];
        sumwp += (mod + p[i] % mod) * w[i] % mod;
        f[0].addR(idx[i], m, (mod + p[i] % mod) * w[i] % mod);
        f[1].addR(idx[i], m, w[i]);
    }

    for (int i = 1; i <= q; i++) cout << ans[i] % mod << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}