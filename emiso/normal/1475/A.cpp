#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    while(n % 2 == 0) n /= 2;
    puts(n == 1 ? "NO" : "YES");
    if(--t) goto st;
    return 0;
}