#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %s", &n, s);

    int cw = 1, ccw = 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '<') cw = 0;
        if(s[i] == '>') ccw = 0;
    }

    ans = 0;
    if(cw || ccw) ans = n;
    else {
        for(int i = 0; i < n; i++)
            if(s[(i+1)%n] == '-' || s[i] == '-')
                ans++;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}