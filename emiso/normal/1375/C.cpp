#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, t, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    if(a[0] < a[n-1]) puts("YES");
    else puts("NO");
    if(--t) goto st;
    return 0;
}