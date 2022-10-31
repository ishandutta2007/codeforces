#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, a, b, c, d;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    puts((max(a, b) > min(c, d) && max(c, d) > min(a, b)) ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}