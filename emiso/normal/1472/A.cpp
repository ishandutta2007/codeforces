#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], w, h;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %lld", &w, &h, &n);

    ans = 1;
    while(w % 2 == 0) {ans *= 2; w /= 2;}
    while(h % 2 == 0) {ans *= 2; h /= 2;}

    puts(ans >= n ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}