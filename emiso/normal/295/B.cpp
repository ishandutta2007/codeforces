#include <bits/stdc++.h>

using namespace std;

#define N 505

int n, dist[N][N], order[N], rev[N];
long long ans[N];

void floyd_warshall() {
    long long total = 0;

    for(int k = n; k >= 1; k--) {
        int pivot = order[k];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if((rev[i] == k && rev[j] > k) || (rev[i] > k && rev[j] == k)) {
                    total += dist[i][j];
                }
                if(dist[i][j] > dist[i][pivot] + dist[pivot][j]) {
                    if(rev[i] > k && rev[j] > k)
                        total = total - dist[i][j] + (dist[i][pivot] + dist[pivot][j]);
                    dist[i][j] = dist[i][pivot] + dist[pivot][j];
                }
            }
        }

        ans[k] = total;
    }
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%lld", &dist[i][j]);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &order[i]);
        rev[order[i]] = i;
    }

    floyd_warshall();

    for(int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);

    return 0;
}