#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, x, y, ans, a[MN], f[256];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %s", &x, &y, s);
    str = s;

    memset(f, 0, sizeof f);
    for(int i = 0; i < str.size(); i++) {
        f[str[i]]++;
    }

    if(x >= 0 && f['R'] >= x) {
        if(y >= 0 && f['U'] >= y) {
            puts("YES");
        }
        else if(y < 0 && f['D'] >= -y) {
            puts("YES");
        }
        else puts("NO");
    }
    else if(x < 0 && f['L'] >= -x) {
        if(y >= 0 && f['U'] >= y) {
            puts("YES");
        }
        else if(y < 0 && f['D'] >= -y) {
            puts("YES");
        }
        else puts("NO");
    }
    else puts("NO");
    if(--t) goto st;
    return 0;
}