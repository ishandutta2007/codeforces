#include <bits/stdc++.h>

#define MN 35035
#define MK 110

using namespace std;
///Divide and Conquer Optimization

int n, K, a[MN], dp[MK][MN], optK[MK][MN], last[MN], prv[MN], nxt[MN];

int L = 1, R = 0, cur;

void addLeft(int i) {
    if (prv[i]) {
        cur += (i - prv[i]);
    }
    if (nxt[i] && nxt[i] <= R) {
        cur -= (nxt[i] - i);
    }
}

void addRight(int i) {
    if (prv[i] && prv[i] < L) {
        cur += (i - prv[i]);
    }
}

void remLeft(int i) {
    if (prv[i]) {
        cur -= (i - prv[i]);
    }
    if (nxt[i] && nxt[i] <= R) {
        cur += (nxt[i] - i);
    }
}

void remRight(int i) {
    if (prv[i] && prv[i] < L) {
        cur -= (i - prv[i]);
    }
}

int C(int l, int r) {
    while (L > l) addLeft(--L);
    while (R < r) addRight(++R);
    while (L < l) remLeft(L++);
    while (R > r) remRight(R--);
    return cur;
}

void calc(int d, int l, int r) {
    if(l > r) return;

    int m = (l + r) / 2;
    int L = optK[d][l-1];
    int R = optK[d][r+1];

    for(int k=L; k<=min(R, m); k++) {
        if(dp[d][m] < dp[d-1][k] + C(k+1, m)) {
            dp[d][m] = dp[d-1][k] + C(k+1, m);
            optK[d][m] = k;
        }
    }
    calc(d, l, m-1);
    calc(d, m+1, r);
}

int tot;

int main() {
    scanf("%d %d ", &n, &K);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (last[a[i]] != 0) {
            prv[i] = last[a[i]];
            nxt[last[a[i]]] = i;
            tot += (i - prv[i]);
        }
        last[a[i]] = i;
    }

    for(int d=0; d<MK; d++)
        for(int i=0; i<MN; i++)
            dp[d][i] = -999999999;
    dp[0][0] = 0;

    for(int d = 1; d <= K; d++) {
        optK[d][0] = 0;
        optK[d][n+1] = n;
        calc(d, 1, n);
    }
    
    printf("%d\n", tot - dp[K][n]);
    return 0;
}