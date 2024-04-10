#include <bits/stdc++.h>

using namespace std;

int n, l, x[1010], b[1010], previ[1010];
double dp[1010];

void cmon(double k) {
    fill(dp, dp + 1010, 1e12);
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int j = i + 1; j <= n; j++) {
            double tmp = dp[j] + sqrt(abs(x[j]-x[i]-l)) - k*b[j];
            if(dp[i] > tmp) {
                dp[i] = tmp;
                previ[i] = j;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &b[i]);
    }

    double l = 0, r = 1000000000, m;
    for(int it = 80; it; it--) {
        m = (l + r) / 2;
        cmon(m);
        if(dp[0] < 0) r = m;
        else l = m;
    }
    cmon(l);
    for(int i = 0; i < n; i = previ[i])
        printf("%d ", previ[i]);
    return 0;
}