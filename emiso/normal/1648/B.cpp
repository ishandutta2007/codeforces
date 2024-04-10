#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 2001000

ll t = 1, n, c, ans, a[MN], f[MN], cant[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &c);

    for (int i = 0; i <= c; i++) {
        cant[i] = f[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]] = 1;
    }

    ans = 1;
    if (f[1] == 0) ans = 0;
    for (int i = 2, tmp = 0; ans && i <= c; i++) {
        tmp += cant[i];
        if (!f[i]) continue;
        if (tmp) ans = 0;
        for (int j = 2*i, k = 2; j <= c; j += i, k++) {
            if (!f[k]) {
                cant[j]--;
                cant[j+i]++;
            }
        }
    }

    puts(ans ? "Yes" : "No");
    if(--t) goto st;
    return 0;
}