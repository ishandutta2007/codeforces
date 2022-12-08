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
const double PI = acos(-1);

template <class T> T sqr(T x) { return x * x; }
template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

const int modnum = 1000000007;

int f[1010][1010], s[1010];

void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    fillchar(f, 0);
    forint (i, 1, 1000)
        f[i][0] = 1;
    forint (j, 1, 1000) {
        int s1 = 0, s2 = 0;
        forint (i, 3, 1000) {
            s1 = (s1 + f[i-2][j-1]) % modnum;
            s2 = (s2 + s1) % modnum;
            f[i][j] = s2;
        }
    }
    int ans = (int)((int64)f[n][k] * (int64)f[m][k] % modnum);
    printf("%d\n", ans);
}

int main() {
    /*
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
    //*/
   // while(1)
    solve();
    return 0;
}