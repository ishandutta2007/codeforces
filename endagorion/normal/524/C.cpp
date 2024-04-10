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

const int X = 1e8 + 100;
char e[X];

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vi a(n);
    forn (i, n)
    {
        cin >> a[i];
        for (int l = 1, w = a[i]; l <= k && w < X; l++, w += a[i]) {
            if (!e[w])
                e[w] = k + 2;
            e[w] = min(e[w], (char)l);
        }
    }
    int q;
    cin >> q;
    forn (iii, q)
    {
        int x;
        cin >> x;
        int ans = k + 2;
        forn (i, n)
        {
            for (int l = 1, cur = a[i]; cur <= x && l <= k; cur += a[i], l++) {
               int rem = x - cur;
               if (rem < X && (e[rem] || !rem)) {
                    ans = min(ans, e[rem] + l); 
               }
            }
        }
        if (ans > k)
            ans = -1;
        cout << ans << "\n";
    }
    return 0;
}