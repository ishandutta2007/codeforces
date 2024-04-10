#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int MOD = 1000000007;

const int maxn = 500005;
const int maxm = 45;

char ss[maxm];
map<ll, int> was[maxm];
pair2<int> p[maxn];
int blocks[maxn];
int ans[maxm];
int n, m;
ll s, forbmask;

int powmod(int a, int b)
{
    int tmp = a;
    int ans = 1;
    while (b)
    {
        if (b & 1) ans = ((ll)ans * tmp) % MOD;
        tmp = ((ll)tmp * tmp) % MOD;
        b >>= 1;
    }
    return ans;
}

string btw(ll x)
{
    string ans = "";
    for (int i = 0; i < m; i++) ans += '0' + ((x >> i) & 1);
    return ans;
}

// ll kk = 0;
int boundmask[maxm];
int shift[maxm];
int scentermask[maxm], fullcentermask[maxm];
int *wh[maxm];
int ttcnt[maxm];
int maxcnt[maxm];
int k;

int was29[(1 << 22) * 18];
int was31[(1 << 18) * 22];
int was37[(1 << 6) * 34];

int vis29 = 0;
int vis31 = 0;
int vis37 = 0;

ll boundmask29, middlemask29;

int go2(int cur, int curmask, int cnt)
{
//     cout << "go2 " << cur << ' ' << cnt << '\t' << btw(curmask) << endl;
    int newmask = (curmask & boundmask[cur]) | ((curmask >> shift[cur]) << (m - p[cur].fi));
    cnt += __builtin_popcount((curmask ^ scentermask[cur]) & fullcentermask[cur]);
    curmask = newmask;
//     cout << "compr " << cur << ' ' << cnt << '\t' << btw(curmask) << ' ' << btw(scentermask[cur]) << ' ' << btw(fullcentermask[cur]) << endl;
    if (cur >= k)
    {
//         cout << "returning " << ans[cnt] << endl;
        return ans[cnt];
    }
    int &whans = wh[cur][curmask * maxcnt[cur] + cnt];
    if (whans != -1) return whans;
    whans = 0;
    if (p[cur].fi == 29) vis29++;
    if (p[cur].fi == 31) vis31++;
    if (p[cur].fi == 37)
    {
        vis37++;
        assert(curmask < (1 << 6) && cnt < 34);
    }
    for (int i = 0; i < m - p[cur].fi; i++) if (ss[i] == '0')
    {
        int npos = i + p[cur].fi;
        int newmask = curmask | (1 << i);
        if (npos < m)
        {
            if (ss[npos] == '1') continue;
            newmask |= (1 << (2 * (m - p[cur].fi) - (m - npos)));
        }
        whans = whans + go2(cur + 1, newmask, cnt);
        if (whans >= MOD) whans -= MOD;
    }
    if (cnt > 0) whans = (whans + (ll)cnt * go2(cur + 1, curmask, cnt - 1)) % MOD;
    whans = (whans + (ll)(ttcnt[cur] - cnt) * go2(cur + 1, curmask, cnt)) % MOD;
//     cout << "ttcnt[cur] " << ttcnt[cur] << endl;
    whans = (whans * (ll)blocks[cur]) % MOD;
    return whans;
}

int go(int cur, ll curmask)
{
//     kk++;
//     if (kk % 10000 == 0)
//     {
//         cerr << kk << ' ' << cur << ' ' << curmask << endl;
//     }
//     cout << "go " << cur << ' ' << btw(curmask) << ' ' << btw(curmask ^ s) << endl;
    if (curmask & forbmask) return 0;
    if (cur >= n || p[cur].fi >= m)
    {
        int cnt = __builtin_popcountll(s ^ curmask);
//         cout << "returning " << ans[cnt] << endl;
        return ans[cnt];
    }
    if (p[cur].fi > 23 && m >= 22)
    {
        int curmask2 = (curmask & boundmask29) | ((curmask >> (m - 11)) << 11);
        int cnt = __builtin_popcountll((s ^ curmask) & middlemask29);
        return go2(cur, curmask2, cnt);
    }
    auto it = was[cur].find(curmask);
    if (it != was[cur].end()) return it->se;
    int curans = 0;
    for (int i = 0; i < p[cur].fi; i++)
    {
        ll newmask = curmask;
        for (int j = i; j < m; j += p[cur].fi) newmask |= 1LL << j;
        curans = (curans + (ll)blocks[cur] * go(cur + 1, newmask)) % MOD;
    }
    was[cur][curmask] = curans;
    return curans;
}

int main()
{
    scanf("%s", ss);
    m = strlen(ss);
    int forb = 0;
    for (int i = 0; i < m; i++)
    {
        s |= ((ll)(1 - (ss[i] - '0')) << i);
        forbmask |= ((ll)(ss[i] - '0') << i);
        if (ss[i] == '1') forb++;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d%d", &p[i].fi, &p[i].se);
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) blocks[i] = powmod(p[i].fi, p[i].se - 1);
    for (int i = 0; i < m; i++) ans[i] = 0;
    ans[0] = 1;
    for (int i = 0; i < n; i++) if (p[i].fi >= m)
    {
        for (int j = m - forb; j >= 0; j--)
        {
            ans[j] = (ll)ans[j] * (p[i].fi - forb - j) % MOD * blocks[i] % MOD;
            if (j > 0) ans[j] = (ans[j] + (ll)ans[j - 1] * j % MOD * blocks[i]) % MOD;
        }
    }
    if (m >= 22)
    {
        int last = 11;
        p[n] = {41, 0};
        for (int i = 0; i <= n; i++) if (p[i].fi >= 29)
        {
            if (p[i].fi >= m)
            {
                k = i;
                boundmask[i] = 0;
                shift[i] = 0;
                for (int j = 0; j < last; j++)
                {
                    scentermask[i] |= (1 - (ss[j] - '0')) << j;
                    fullcentermask[i] |= 1 << j;
                }
                for (int j = 0; j < last; j++)
                {
                    scentermask[i] |= (1 - (ss[m - last + j] - '0')) << (last + j);
                    fullcentermask[i] |= 1 << (last + j);
                }
                break;
            }
            boundmask[i] = (1 << (m - p[i].fi)) - 1;
            shift[i] = last + last - (m - p[i].fi);
            for (int j = m - p[i].fi; j < last; j++)
            {
                scentermask[i] |= (1 - (ss[j] - '0')) << j;
                fullcentermask[i] |= 1 << j;
            }
            for (int j = 0; j < last - (m - p[i].fi); j++)
            {
                scentermask[i] |= (1 - (ss[m - last + j] - '0')) << (last + j);
                fullcentermask[i] |= 1 << (last + j);
            }
            ttcnt[i] = __builtin_popcountll((s >> (m - p[i].fi)) & ((1LL << (2 * p[i].fi - m)) - 1));
            if (p[i].fi == 29)
            {
                wh[i] = was29;
                maxcnt[i] = 18;
            }
            if (p[i].fi == 31)
            {
                wh[i] = was31;
                maxcnt[i] = 22;
            }
            if (p[i].fi == 37)
            {
                wh[i] = was37;
                maxcnt[i] = 34;
            }
            last = m - p[i].fi;
        }
        boundmask29 = (1 << (m - 29)) - 1;
        for (int j = 11; j + 11 < m; j++) middlemask29 |= 1LL << j;
        memset(was29, -1, sizeof(was29));
        memset(was31, -1, sizeof(was31));
        memset(was37, -1, sizeof(was37));
    }
    cout << go(0, 0) << endl;
//     cerr << was[n - 1].size() << endl;
    cerr << vis29 << ' ' << vis31 << ' ' << vis37 << endl;
#ifdef LOCAL_DEFINE
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
#endif
    return 0;
}