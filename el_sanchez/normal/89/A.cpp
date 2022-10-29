#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)

typedef long long int64;

const int MAXN = (int)11000;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int64 n, m, k, a[MAXN], ans, t;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d %d\n", &n, &m, &k);
    forn(i, n) scanf("%d", &a[i]);

    if (odd(n) && (n / 2 + 1 <= m)) {
        ans = a[0];
        forn(i, n)
            if (!odd(i))
                ans = min(ans, a[i]);
        t = m / (n / 2 + 1);
        ans = min(ans, k * t);
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}