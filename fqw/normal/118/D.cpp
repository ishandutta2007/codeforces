#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long int64;
typedef unsigned long long qword;
typedef unsigned int uint;

const int INFI_INT = 1<<30;
const int64 INFI_INT64 = (int64)(1<<30) * (int64)(1<<30);
const double PI = 3.14159265358979323846264338;

template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

const int modnum = 100000000;

int f[111][111][15], g[111][111][15];
int n1, n2, k1, k2;

void solve() {
    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
    fillchar(f, 0);
    fillchar(g, 0);
    f[1][0][1] = 1;
    g[0][1][1] = 1;
    forint (i, 0, n1)
        forint (j, 0, n2) {
            forint (k, 0, k1) {
                //printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
                (f[i+1][j][k+1] += f[i][j][k]) %= modnum;
                (g[i][j+1][1] += f[i][j][k]) %= modnum;
            }
            forint (k, 0, k2) {
                //printf("g[%d][%d][%d] = %d\n", i, j, k, g[i][j][k]);
                (f[i+1][j][1] += g[i][j][k]) %= modnum;
                (g[i][j+1][k+1] += g[i][j][k]) %= modnum;
            }
        }
    int ans = 0;
    forint (k, 0, k1)
        (ans += f[n1][n2][k]) %= modnum;
    forint (k, 0, k2)
        (ans += g[n1][n2][k]) %= modnum;
    printf("%d\n", ans);
}

int main() {
    /*
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
    //*/
    /*
  	for (;;)
    //*/
    solve();
    return 0;
}