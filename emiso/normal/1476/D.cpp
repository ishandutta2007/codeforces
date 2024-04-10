#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], al[MN], ar[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %s", &n, s);

    al[0] = ar[n-1] = 1;
    for(int i = 1; i < n; i++) {
        al[i] = al[i-1]*(s[i] != s[i-1]) + 1;
    }
    for(int i = n-2; i >= 0; i--) {
        ar[i] = ar[i+1]*(s[i] != s[i+1]) + 1;
    }

    for(int i = 0; i <= n; i++) {
        ans = 1;
        if(i && s[i-1] == 'L') ans += al[i-1];
        if(i<n && s[i] == 'R') ans += ar[i];
        printf("%lld ", ans);
    } puts("");
    if(--t) goto st;
    return 0;
}