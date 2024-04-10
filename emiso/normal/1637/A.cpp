#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    puts(is_sorted(a, a + n) ? "NO" : "YES");
    if(--t) goto st;
    return 0;
}