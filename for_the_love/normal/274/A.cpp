#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

map <int, int> s;
int n, k, i, a[100005], v[100005], f[100005], ans;
int main(){
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++){
        if (a[i] % k == 0 && s[a[i] / k]){
            f[i] = f[s[a[i] / k]] + 1;
            v[s[a[i] / k]] = 1;
        }
        s[a[i]] = i;
    }
    for (i = 1; i <= n; i++)
    if (!v[i]){
        f[i]++;
        if (f[i] % 2 == 0) ans += f[i] / 2; else ans += f[i] / 2 + 1;
    }
    printf("%d\n", ans);
}