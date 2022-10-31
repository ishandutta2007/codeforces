#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, q, p, a[MN], l[MN], r[MN], par[MN];
char s[MN]; string str;

int main() {
    scanf("%lld %s %lld", &n, s, &q); str = " "; str += s;
    for(int i = 1; i <= (1<<(n-1)); i++)
        a[i] = 1 + (str[i] == '?');

    for(int i = (1<<(n-1))+1, ch = 1; i < (1 << n); i++) {
        l[i] = ch++; par[l[i]] = i;
        r[i] = ch++; par[r[i]] = i;
        a[i] = (str[i] != '1') * a[l[i]] + (str[i] != '0') * a[r[i]];
    }

    while(q--) {
        scanf("%lld %s", &p, s);
        str[p] = s[0];
        while(1) {
            if(p <= (1 << (n-1))) a[p] = 1 + (str[p] == '?');
            else a[p] = (str[p] != '1') * a[l[p]] + (str[p] != '0') * a[r[p]];
            if(p == (1 << n) - 1) break;
            p = par[p];
        }
        printf("%lld\n", a[(1<<n)-1]);
    }
    return 0;
}