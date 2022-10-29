#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = (int)1E9;
const int MAXN = (int)11000;

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, pos = 0, last, newpos, ans = 0;
    scanf("%d%d\n", &n, &m);
    int l[n], r[n];
    bool any[n];
    char c[m];

    forn(i, n) {
        l[i] = m - 1;
        r[i] = 0;
        any[i] = 0;

        forn(j, m) {
            scanf("%c", &c[j]);
            if (c[j] == 'W') {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
                any[i] = 1;
            }
        }

        scanf("\n");
    }

    for (last = n - 1; last >= 0 && !(any[last]); last--) {}

    forn(i, last) {
        if (i % 2 == 0) {
            newpos = max(pos, max(r[i], r[i + 1]));
            ans += newpos - pos;
        } else {
            newpos = min(pos, min(l[i], l[i + 1]));
            ans += pos - newpos;
        }
        pos = newpos;
        ans++;
    }

    if (last >= 0 && last % 2 == 0) {
            newpos = max(pos, r[last]);
            ans += newpos - pos;
    } else {
            newpos = min(pos, l[last]);
            ans += pos - newpos;
    }
    cout << ans << endl;

    return 0;
}