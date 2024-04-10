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
const int N = 100500, HQ = 2;
const int mod[HQ] = {1e9 + 7, 1e9 + 9};
const int p[HQ] = {239, 3131};
i64 powers[N][HQ];
i64 h[N][HQ];
vll calc(const string& s)
{
    forn (i, s.length())
    forn (j, 2)
    {
        h[i + 1][j] = (h[i][j] + s[i] * powers[i][j]) % mod[j]; 
    }
    vll res(s.length() + 1);
    forn (i, res.size())
        res[i] = mp(h[i][0], h[i][1]);
    return res;
}

int n;
vll app(const vll& a)
{
    vll res;
    forn (i, n + 1)
    forn (j, 26)
    {
        char c = j + 'a';
        pii w;
        w.fi = (a[i].fi + powers[i][0] * c + (a.back().fi - a[i].fi) * p[0]) % mod[0];
        w.se = (a[i].se + powers[i][1] * c + (a.back().se - a[i].se) * p[1]) % mod[1];
        w.fi = (w.fi + mod[0]) % mod[0];
        w.se = (w.se + mod[1]) % mod[1];
        res.pb(w);
    }
    return res;
}

void pr(const vll& a)
{
    for (auto x: a)
        cerr << x.fi << " " << x.se << endl;
}

int main()
{
    forn (i, HQ) powers[0][i] = 1;
    forn (i, N - 1)
        forn (j, HQ)
            powers[i + 1][j] = (powers[i][j] * p[j]) % mod[j]; 
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    string s, t;
    cin >> s >> t;
    //n = 100000;
    //s = string(n, 'a');
    //t = string(n, 'a');
    vll hs = calc(s);
    vll ht = calc(t);
    vll as = app(hs);
    vll at = app(ht);
    sort(all(as));
    sort(all(at));
    as.resize(unique(all(as)) - as.begin());
    at.resize(unique(all(at)) - at.begin());
    size_t i = 0, j = 0;
    int q = 0;
    while (i < as.size() && j < at.size()) {
        if (as[i] == at[j])
            q++;
        if (as[i] <= at[j])
            i++;
        else
            j++;
    }
    cout << q << "\n";
    return 0;
}