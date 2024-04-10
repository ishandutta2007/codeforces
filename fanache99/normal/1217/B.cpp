#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int d[1 + MAXN], h[1 + MAXN];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int n, x, bestD = 0, bestDif = 0, answer;
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &d[i], &h[i]);
            bestDif = max(bestDif, d[i] - h[i]);
            bestD = max(bestD, d[i]);
        }
        if (bestD >= x)
            answer = 1;
        else
            if (bestDif == 0)
                answer = -1;
            else
                answer = 1 + (x - bestD - 1) / bestDif + 1;
        printf("%d\n", answer);
    }
    return 0;
}