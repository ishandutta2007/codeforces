#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[5001], ans;
int L[5001], R[5001], f[5001], cmf[5001], s[5001];

void init_LR() {
    fill(L, L + 5001, -1);
    for (int i = 1; i <= n; ++i) {
        if (L[a[i]] == -1)
            L[a[i]] = i;
        R[a[i]] = i;
    }
}

void init_cmf() {
    for (int i = 1; i <= n; ++i) {
        int Left = L[a[i]], Right = R[a[i]], j = i;
        cmf[i] = a[i];
        while (j != Left && i == Right) {
            j--;
            if (j == R[a[j]])
                cmf[i] ^= a[j];
            Left = min(Left, L[a[j]]);
            Right = max(Right, R[a[j]]);
        }
        if (i != Right)
            f[i] = 0;
        else f[i] = j;
    }
}

void Solve() {
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1];
        if (f[i] > 0)
            s[i] = max(s[i], s[f[i] - 1] + cmf[i]);
    }
    ans = s[n];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    init_LR();
    init_cmf();
    Solve();
    printf("%d", ans);
    return 0;
}