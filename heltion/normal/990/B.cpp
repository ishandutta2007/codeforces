#include<cstdio>
#include<algorithm>
#define MAXN 240000
int a[MAXN];
int main(){
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i += 1) scanf("%d", a + i);
    std::sort(a, a + n);
    for(int i = 0; i < n - 1; i += 1){
        int p = std::lower_bound(a, a + n, a[i] + 1) - a;
        if(p < n && a[p] <= a[i] + k) ans += 1;
    }
    printf("%d", n - ans);
}