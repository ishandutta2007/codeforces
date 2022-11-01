#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, m, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &m);

    if(n * 2 <= m) puts("NO");
    else puts("YES");
    if(--t) goto st;
    return 0;
}