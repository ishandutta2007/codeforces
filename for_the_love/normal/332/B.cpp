#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int a[2000005];
long long s[2000005], f[200005][3];
int g[200005][3];
int main(){
    int n, k;
    long long sum = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++){
        sum += a[i];
        if (i > k) sum -= a[i - k];
        if (i >= k) s[i] = sum;
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++){
        f[i][1] = f[i - 1][1];
        g[i][1] = g[i - 1][1];
        f[i][2] = f[i - 1][2];
        g[i][2] = g[i - 1][2];
        if (f[i - k][1] + s[i] > f[i][2]){
            f[i][2] = f[i - k][1] + s[i];
            g[i][2] = i - k;
        }
        if (s[i] > f[i][1]){
            f[i][1] = s[i];
            g[i][1] = i - k;
        }
    }
    long long ans = 0;
    int p = 0;
    for (int i = 1; i <= n; i++)
    if (f[i][2] > ans){
        ans = f[i][2];
        p = i;
    }
    printf("%d %d\n", g[g[p][2]][1] + 1, g[p][2] + 1);

}