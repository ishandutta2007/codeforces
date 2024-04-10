#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, d, i;
int a[100005];
long long ans, t;
int main(){
    scanf("%d%d", &n, &d);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    t = 1; ans = 0;
    for (i = 1; i <= n; i++){
        while (a[i] + d >= a[t] && t <= n) t++;
        t--;
        if (t - i > 1) ans = ans + (t - i - 1) * (t - i) / 2;
    }
    cout << ans << endl;
}