#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, k, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld %s", &n, &k, s);
    
    str = s;
    bool isp = true;
    for (int l = 0, r = n-1; l < r; l++, r--) {
        if (str[l] != str[r]) isp = false;
    }

    if (k == 0) puts("1");
    else printf("%d\n", isp ? 1 : 2);
    if(--t) goto st;
    return 0;
}