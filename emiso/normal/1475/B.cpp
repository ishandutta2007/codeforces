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

    ll t2 = n / 2020;

    puts((t2 >= (n % 2020)) ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}