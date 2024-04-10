#include <bits/stdc++.h>

using namespace std;

int n, p, a[51], ok[51][51][51][51], lim;
double dp[51][51][51][51], fat[55];

double solve(int i, int in, int rem, int big) {
    if(i == n) {
        if(rem) return 0;
        if(in == n) return in;
        return fat[in] * big * fat[n-in-1] * in / fat[n];
    }

    double &x = dp[i][in][rem][big];
    if(ok[i][in][rem][big] == lim) return x;
    ok[i][in][rem][big] = lim;

    x = solve(i + 1, in, rem, big + (a[i] > lim));
    if(a[i] <= rem)
        x += solve(i + 1, in + 1, rem - a[i], big);

    return x;
}

int main() {
    fat[0] = 1;
    for(int i = 1; i <= 50; i++) fat[i] = fat[i-1] * i;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &p);

    double ans = 0;
    memset(ok, -1, sizeof ok);
    for(lim = 0; lim <= p; lim++) {
        ans += solve(0, 0, p-lim, 0);
    }
    printf("%.9f\n", ans);
    return 0;
}