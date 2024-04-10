#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], minl[MN], minr[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    minl[0] = a[0];
    minr[n-1] = a[n-1];
    for(int i = 1; i < n; i++) {
        minl[i] = min(a[i], minl[i-1]);
    }
    for(int i = n-2; i >= 0; i--) {
        minr[i] = min(a[i], minr[i+1]);
    }

    int flag = 1, saldo = a[0], acum = 0;
    for(int i = 1; flag && i < n; i++) {
        a[i] -= acum;
        if(a[i] < 0) flag = 0;
        else if(a[i] > saldo) acum += (a[i] - saldo);
        else saldo = a[i];
    }
    puts(flag ? "YES" : "NO");

    if(--t) goto st;
    return 0;
}