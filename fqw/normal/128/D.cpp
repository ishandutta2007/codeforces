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

const int maxn = 100010;

int a[maxn];
int n;

bool solve() {
    scanf("%d", &n);
    forint (i, 1, n)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int last = 0;
    for (int i = 1, j; i <= n; i = j+1) {
        if (i > 1 && a[i] != a[i-1]+1)
            return false;
        for (j = i; j < n && a[j+1] == a[j]; ++ j);
        int cnt = j-i+1;
        if (cnt < last)
            return false;
        last = cnt - last;
        if (j < n && last == 0)
            return false;
    }
    return last == 0;
}

int main() {
    /*
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
    //*/
 //   while(1)
    printf("%s\n", solve() ? "YES" : "NO");
    return 0;
}