#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int i, j, k, n, d[505][505], x[505];
long long ans[505];
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
        scanf("%d", &d[i][j]);
    for (i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (k = n; i >= 1; k--){
        for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            d[i][j] = min(d[i][j], d[i][x[k]] + d[x[k]][j]);
        for (i = n; i >= k; i--)
        for (j = n; j >= k; j--)
            ans[k] += d[x[i]][x[j]];
    }
    for (i = 1; i <= n; i++) cout << ans[i] << " ";
}