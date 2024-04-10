#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int d[1000005];
int p[1000005][10];

void init() {
    for (int i = 1; i < 10; ++i) {
        d[i] = i;
    }
    for (int i = 10; i <= 1000000; ++i) {
        int res = 1;
        for (int j = i; j > 0; j /= 10) {
            int dig = j % 10;
            if (dig > 0) {
                res *= dig;
            }
        }
        d[i] = d[res];
    }
    for (int i = 1; i <= 1000000; ++i) {
        forn(j, 10) {
            p[i][j] = p[i - 1][j];
        }
        ++p[i][d[i]];
    }
}

int main() {
    init();
    int q;
    scanf("%d", &q);
    forn(_, q) {
        int from, to, k;
        scanf("%d%d%d", &from, &to, &k);
        int ans = p[to][k] - p[from - 1][k];
        printf("%d\n", ans);
    }
    return 0;
}