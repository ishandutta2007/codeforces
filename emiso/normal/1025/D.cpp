#include <bits/stdc++.h>
#define MN 702

using namespace std;

int n, a[MN], can[MN][MN];
char dpL[MN][MN], dpR[MN][MN];

char solveR(int l, int r);

char solveL(int l, int r) {
    if(l == r) return 1;
    char &x = dpL[l][r];
    if(x != -1) return x;

    x = 0;
    for(int i = l; i < r && !x; i++)
        if(can[i][r]) x |= (solveL(l, i) && solveR(i, r-1));

    return x;
}

char solveR(int l, int r) {
    if(l == r) return 1;
    char &x = dpR[l][r];
    if(x != -1) return x;

    x = 0;
    for(int i = l + 1; i <= r && !x; i++)
        if(can[l][i]) x |= (solveL(l+1, i) && solveR(i, r));

    return x;
}

int main() {
    scanf("%d", &n);
    memset(dpL, -1, sizeof dpL);
    memset(dpR, -1, sizeof dpR);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(__gcd(a[i], a[j]) > 1)
                can[i][j] = can[j][i] = 1;

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans |= (solveL(0, i) & solveR(i, n-1));

    printf("%s\n", ans ? "Yes" : "No");
    return 0;
}