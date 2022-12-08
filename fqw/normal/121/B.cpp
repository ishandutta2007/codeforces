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

char a[100010];
int n, k;

void solve() {
    scanf("%d%d%s", &n, &k, a);
    for (int i = 0; i+1 < n && k > 0; )
        if (a[i] == '4' && a[i+1] == '7') {
            -- k;
            if (i % 2 == 0)
                a[i+1] = '4';
            else {
                a[i] = '7';
                if (i > 0 && a[i-1] == '4') {
                    a[i] = (k % 2 == 0 ? '7' : '4');
                    k = 0;
                }
            }
        } else
            ++ i;
    printf("%s\n", a);
}

int main() {
    /*
7 1000000000
4727447
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
    //*/
  //  while(1)
    solve();
    return 0;
}