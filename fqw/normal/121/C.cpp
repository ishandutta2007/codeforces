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


int64 xa[9999];
int len;

void search(int64 x) {
    if (x > 4444444444LL)
        return;
    xa[++ len] = x;
    search(x*10 + 4);
    search(x*10 + 7);
}

bool check(int x) {
    for (; x > 0; x /= 10)
        if (x % 10 != 4 && x % 10 != 7)
            return false;
    return true;        
}

bool get_per(int n, int64 k, int p[]) {
    int rest[22];
    forint (i, 1, n) rest[i] = i;
    
    int64 u[22];
    u[0] = 1;
    forint (i, 1, 13) u[i] = u[i-1] * (int64)i;
    if (k+1 > u[n]) return false;
    forint (i, 1, n) {
        int x = k / u[n-i] + 1;
        k = k % u[n-i];
        p[i] = 0;
        while (x > 0) {
            ++ p[i];
            -- x;
            forint (j, 1, i-1)
                if (p[j] == p[i])
                    ++ x;
        }
    }
    return true;
}

void solve() {
    int n, k, p[22], la;
    scanf("%d%d", &n, &k);
    if (!get_per(la = min(n, 13), (int64)k-1, p)) {
        printf("-1\n");
        return;
    }
  //  printf("   per = ");forint(i,1,la)printf("%d, ",p[i]);printf("\n");
    
    int ans = 0;
    
    len = 0;
    search(4); search(7);
    for (int i = 1; i <= len; ++ i)
        if (xa[i] <= n-la)
            ++ ans;
            
    for (int i = 1; i <= la; ++ i)
        if (check(n-la+p[i]) && check(n-la+i))
            ++ ans;
        
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