#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k, i, mx, ans, cnt;
int f[1000000],a[1000000];
int main(){
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) {
        cnt++;
        scanf("%d", &a[cnt]);
        if (a[cnt] == a[cnt - 1]) cnt--;
    }
    n = cnt;
    a[0] = a[2]; a[n + 1] = a[n - 1];
    for (i = 1; i <= n; i++){
        int c1=0,c2=0;
        if (a[i - 1] != a[i + 1]) c1++;
        if (a[i] != a[i - 1] && i - 1 > 0 ) c2++;
        if (a[i] != a[i + 1] && i + 1 <= n) c2++;
        f[a[i]] += c2 - c1;
    }
    mx = - 10000000;
    for (i = 1; i <= k; i++)
    if (f[i] > mx) { mx = f[i]; ans = i;}
    printf("%d\n", ans);
}