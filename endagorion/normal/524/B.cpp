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

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vi w(n), h(n);
    forn (i, n) {
        cin >> w[i] >> h[i];
        if (w[i] < h[i]) swap(w[i], h[i]);
    }
    int ans = 2e9;
    int mnH = 0;
    for (int x: h)
        mnH = max(mnH, x);
    for (int H = mnH; H <= 1000; H++)
    {
        int W = 0;
        forn (i, n)
        {
            if (w[i] <= H)
                W += h[i];
            else
                W += w[i];
        }
        ans = min(ans, W * H);
    }
    cout << ans << "\n";
    return 0;
}