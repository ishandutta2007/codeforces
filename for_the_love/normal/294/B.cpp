#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, i, k, j, sum, t[105], w[105], f[300];
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d%d", &t[i], &w[i]);
        sum += w[i];
    }
    for (k = 1; k <= n * 2; k++){
        for (i = 0; i <= k; i++) f[i] = -1e9;
        f[0] = 0;
        for (i = 1; i <= n; i++)
        for (j = k; j >= t[i]; j--)
            f[j] = max(f[j], f[j - t[i]] + w[i]);
        if (sum - f[k] <= k){
            printf("%d\n", k);
            return 0;
        }
    }

}