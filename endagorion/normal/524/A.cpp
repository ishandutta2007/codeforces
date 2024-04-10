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

map<int, vi> g;

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    int m, k;
    cin >> m >> k;
    vector<int> vs;
    forn (i, m)
    {
        int u, v;
        cin >> u >> v;
        vs.pb(u);
        vs.pb(v);
        g[u].pb(v);
        g[v].pb(u);
    }
    sort(all(vs));
    vs.resize(unique(all(vs)) - vs.begin());
    int n = vs.size();
    forn (i, n)
    {
        cout << vs[i] << ": ";
        vi ans;
        set<int> cur;
        for (int x: g[vs[i]])
            cur.insert(x);
        forn (j, n)
        if (i != j)
        {
            if (cur.count(vs[j]))
                continue;
            int q = 0;
            for (int x: g[vs[j]])
                if (cur.count(x))
                    q++;
            if (q * 100 >= cur.size() * k)
                ans.pb(vs[j]);
        }
        cout << ans.size();
        for (int x: ans)
            cout << " " << x;
        cout << "\n";
    }
    return 0;
}