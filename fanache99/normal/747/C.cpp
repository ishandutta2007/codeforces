#include <cstdio>
//#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

const int MAXN = 100;

int free[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        int t, k, d;
        scanf("%d%d%d", &t, &k, &d);
        int answer = 0, found = 0;
        for (int i = 1; i <= n && found < k; i++)
            if (free[i] <= t) {
                answer += i;
                found++;
            }
        if (found < k) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", answer);
        found = 0;
        for (int i = 1; i <= n && found < k; i++)
            if (free[i] <= t) {
                free[i] = t + d;
                found++;
            }
    }
    return 0;
}