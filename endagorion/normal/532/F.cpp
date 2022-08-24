#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;

template <class T> T inline sqr(T x) {
        return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

typedef vector<pair<i64, i64>> vll;
const int N = 200500, HQ = 2, ALP = 26;
const int mod[HQ] = {1e9 + 7, 1e9 + 9};
const int p[HQ] = {239, 3131};
i64 powers[N][HQ];
i64 h[N][HQ];
i64 rev[HQ];

i64 spow(i64 x, int n, i64 mod)
{
    i64 r = 1;
    while (n)
    {
        if (n & 1)
            r = (r * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return r;
}

vll calc(const string& s)
{
    vll res(ALP);
    forn (i, s.length())
    {
        int c = s[i] - 'a';
        res[c].fi += powers[i][0];
        res[c].se += powers[i][1];
    }
    forn (i, ALP) res[i].fi %= mod[0], res[i].se %= mod[1];
    return res;
}

int match[ALP];
pair<pii, int> a[ALP], b[ALP];
int T = 0;
bool good(const vll& a1, const vll& b1)
{
    //cerr << "Match " << ++T << endl;
    forn (i, ALP) match[i] = -1;
    int sa = 0, sb = 0;
    forn (i, ALP)
        if (a1[i].fi || a1[i].se)
            a[sa++] = mp(a1[i], i);
    forn (i, ALP)
        if (b1[i].fi || b1[i].se)
            b[sb++] = mp(b1[i], i);
    if (sa != sb) return false;
    sort(a, a + sa);
    sort(b, b + sb);
    //forn (i, sa) cerr << a[i].fi.fi << " " << a[i].se << " "; cerr << endl;
    //forn (i, sa) cerr << b[i].fi.fi << " " << b[i].se << " "; cerr << endl;
    forn (i, sa)
    {
        if (a[i].fi == b[i].fi)
        {
            if (match[a[i].se] != -1 && match[a[i].se] != b[i].se)
                return false;
            match[a[i].se] = b[i].se;
            if (match[b[i].se] != -1 && match[b[i].se] != a[i].se)
                return false;
            match[b[i].se] = a[i].se;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    forn (i, HQ) powers[0][i] = 1, rev[i] = spow(p[i], mod[i] - 2, mod[i]);
    forn (i, N - 1)
        forn (j, HQ)
            powers[i + 1][j] = (powers[i][j] * p[j]) % mod[j]; 
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    cin.sync_with_stdio();
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vll cs = calc(s.substr(0, m));
    vll ct = calc(t);
    vi ans;
    if (good(cs, ct))
        ans.pb(0);
    forn (i, n - m)
    {
        int pr = s[i] - 'a';
        cs[pr].fi = (cs[pr].fi - 1 + mod[0]) % mod[0];
        cs[pr].se = (cs[pr].se - 1 + mod[1]) % mod[1];
        forn (i, ALP) {
            cs[i].fi = (cs[i].fi * rev[0]) % mod[0];
            cs[i].se = (cs[i].se * rev[1]) % mod[1];
        }
        int ne = s[i + m] - 'a';
        cs[ne].fi = (cs[ne].fi + powers[m - 1][0]) % mod[0];
        cs[ne].se = (cs[ne].se + powers[m - 1][1]) % mod[1];
        
        if (good(cs, ct))
            ans.pb(i + 1);
    }

    cout << ans.size() << "\n";
    for (int x: ans)
        cout << x + 1 << " ";
    cout << "\n";
    return 0;
}