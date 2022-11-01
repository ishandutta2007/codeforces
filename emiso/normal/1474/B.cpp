#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

bool isp(int x) {
    if(x < 2) return false;
    if(x == 2) return true;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ll d = n + 1, d2 = 2*n+1;
    while(!isp(d)) {
        d++;
        d2++;
    }
    while(!isp(d2)) d2++;

    printf("%lld\n", d * d2);
    if(--t) goto st;
    return 0;
}