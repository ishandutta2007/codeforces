#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a, b, c;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %lld", &a, &b, &c);

    if((a + b + c) % 9 || min({a, b, c}) < (a + b + c) / 9) puts("NO");
    else puts("YES");

    if(--t) goto st;
    return 0;
}