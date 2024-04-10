#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

ULL d[11][11][100];
ULL c[200][200];

void calcC() {
    forn(i, 200) c[0][i] = 0;
    c[0][0] = 1;
    for (int i = 1; i < 200; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 200; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

void calcD() {
    d[0][0][0] = 1;
    forn(i, 11) forn(j, 11) if (i != 0 || j != 0) forn(k, 100) {
        ULL &res = d[i][j][k] = 0;
        if (i > 0) {
            for (int cnt = 1; cnt <= k; cnt += 2) {
                res += d[i - 1][j][k - cnt] * c[k][cnt];
            }
        } else {
            for (int cnt = 0; cnt <= k; cnt += 2) {
                res += d[i][j - 1][k - cnt] * c[k][cnt];
            }
        }
    }
}

int dig[100];
int cnt[10], odd;

LL solve(int b, LL to) {
    if (to < b) {
        return 0;
    }
    int n = 0;
    while (to > 0) {
        dig[n++] = to % b;
        to /= b;
    }
    LL ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (b - 1) * d[1][b - 1][i - 1];
    }
    forn(i, b) cnt[i] = 0;
    odd = 0;
    for (int i = n - 1; i >= 0; --i) {
        forn(j, dig[i] + (i == 0)) {
            if (i == n - 1 && j == 0) {
                continue;
            }
            if (++cnt[j] & 1) ++odd;
            else --odd;
            ans += d[odd][b - odd][i];
            if (--cnt[j] & 1) ++odd;
            else --odd;
        }
        if (++cnt[dig[i]] & 1) ++odd;
        else --odd;
    }
    return ans;
}

int main() {
//    freopen("input.txt", "r", stdin);
    calcC();
    calcD();
    int q, b;
    LL from, to;
    scanf("%d", &q);
    forn(i, q) {
        scanf("%d%I64d%I64d", &b, &from, &to);
        LL res = solve(b, to) - solve(b, from - 1);
        printf("%I64d\n", res);
    }
    return 0;
}