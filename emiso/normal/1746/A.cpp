#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    int has1 = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        has1 |= (a[i] == 1);
    }

    puts(has1 ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}