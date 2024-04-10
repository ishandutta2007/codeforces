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

vector<int> a[99999];

void solve() {
    int n, k;
    scanf("%d", &n);
    k = 1;
    while (k*(k+1)/2 <= n)
        ++ k;
    int cur = 0;
    forint (i, 1, k)
        a[i].clear();
    forint (i, 1, k)
        forint (j, i+1, k) {
            ++ cur;
            a[i].push_back(cur);
            a[j].push_back(cur);
        }
    printf("%d\n", k);
    forint (i, 1, k)
        for (int j = 0; j < a[i].size(); ++ j)
            printf("%d%c", a[i][j], j<a[i].size()-1?' ':'\n');
}

int main() {
    /*
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
    //*/
  //  for(;;)
    solve();
    return 0;
}