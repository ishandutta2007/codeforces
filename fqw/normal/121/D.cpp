// 810215
// 810167
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

template <class T> T sqr(T x) { return x * x; }
template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

const int64 INFI = (int64)2E18;
const int maxn = 100010;

int64 xa[1001111];
int64 cl[1001111], cr[1001111];
int len;

void search(int64 x) {
    xa[++ len] = x;
    if (x < (int64)1E17)
        search(x*10 + 4), search(x*10 + 7);
}

int64 le[maxn], ri[maxn];
int64 k, min_delta;
int n;

int64 mult(int64 a, int64 b) {
    if (b > 0 && a > INFI / b)
        return INFI;
    else
        return a * b;
}

int64 add(int64 a, int64 b) {
    if (a > INFI - b)
        return INFI;
    else
        return a + b;
}

bool chk(int i, int j) {
    return xa[j]-xa[i] <= min_delta && add(cl[i], cr[j]) <= k;
}

void solve() {
    scanf("%d%I64d", &n, &k);
    min_delta = (int64)1E18;
    forint (i, 1, n) {
        scanf("%I64d%I64d", &le[i], &ri[i]);
        min_delta = min(min_delta, ri[i] - le[i]);
    }
    sort(le+1, le+n+1);
    sort(ri+1, ri+n+1);
    
    len = 0; search(4); search(7);
    sort(xa+1, xa+len+1);
    
    int64 sum = 0, cnt = 0;
    int k = 1;
    forint (i, 1, len) {
        if (i > 1)
            sum = add(sum, mult(cnt, xa[i]-xa[i-1]));
        while (k <= n && ri[k] <= xa[i]) {
            sum = add(sum, xa[i]-ri[k]);
            ++ cnt;
            ++ k;
        }
        cr[i] = sum;
    }
    sum = 0, cnt = 0, k = n;
    forintdown (i, len, 1) {
        if (i < len)
            sum = add(sum, mult(cnt, xa[i+1]-xa[i]));
        while (k >= 1 && xa[i] <= le[k]) {
            sum = add(sum, le[k]-xa[i]);
            ++ cnt;
            -- k;
        }
        cl[i] = sum;
    }
    
   // forint (i, 1, 4) printf("xa[i]=%I64d  cl[i]=%I64d cr[i]=%I64d\n", xa[i], cl[i], cr[i]);
    int ans = 0, j = 1;
    forint (i, 1, len) {
        j = max(j, i);
        while (j <= len && chk(i, j))
            ++ j;
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
}

int main() {
    /*
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
    //*/
   // for(;;)
    solve();
    return 0;
}