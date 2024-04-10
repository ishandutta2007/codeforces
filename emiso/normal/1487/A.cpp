#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], f[110], mini = 110;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    mini = 110;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mini = min(mini, a[i]);
        f[a[i]]++;
    }

    printf("%lld\n", n - f[mini]);
    memset(f, 0, sizeof f);
    if(--t) goto st;
    return 0;
}