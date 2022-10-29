#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10000], v[1000005], u[1000005], f[1000005];
int n, i, j, k, ans, res;
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = -1;
    for (i = 1; i <= n; i++){
        f[a[i]]++;
        ans = max(ans, f[a[i]]);
    }
    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; i++)
    if (!u[a[i]]){
        u[a[i]] = 1;
        for (j = i + 1; j <= n; j++)
        if (a[j] != a[i]){
            if (!v[a[j]]){
                f[a[j]]++;
            }
            v[a[j]] = 1;
        }else{
            for (k = j - 1; a[k] != a[i]; k--){
                if (v[a[k]]) f[a[k]]++;
                v[a[k]] = 0;
            }
        }
        for (j = i + 1; j <= n; j++){
            ans = max(ans, f[a[j]] + 1);
            f[a[j]] = 0;
            v[a[j]] = 0;
        }
    }
    printf("%d\n", ans);
}