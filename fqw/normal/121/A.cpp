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

int64 a[9999];
int len;

void search(int64 x) {
    if (x > 4444444444LL)
        return;
    a[++ len] = x;
    search(x*10 + 4);
    search(x*10 + 7);
}

int64 cal(int64 n) {
    int64 le = 1;
    int64 ans = 0;
    for (int i = 1; i <= len; ++ i) {
        int64 ri = min(n, a[i]);
        ans += (ri - le + 1) * a[i];
        le = ri + 1;
    }
    return ans;
}

void solve() {
    len = 0;
    search(4);
    search(7);
    sort(a+1, a+len+1);
   // cout << "len = " << len << endl;
    
    int64 l, r;
    cin >> l >> r;
    int64 ans = cal(r) - cal(l-1);
    cout << ans << endl;
}

int main() {
    /*
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
    //*/
    ///for(;;)
    solve();
    return 0;
}