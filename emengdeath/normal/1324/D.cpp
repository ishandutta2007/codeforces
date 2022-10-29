#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000000], id[1000000], f[1000000];
int n;
void ins(int x) {
    while (x <= n) {
        f[x] ++;
        x += x & -x;
    }
}
int get(int x) {
    int y = 0;
    while (x) {
        y += f[x];
        x -= x & -x;
    }
    return y;
}
int keep(int x) {
    return x <= n? x : x - n;
}
int main() {
    scanf("%d", &n);
    for (int i = 1;i <= n; i ++)
        scanf("%d", &a[i]);
    for (int i = 1;i <= n; i ++) {
        int x;
        scanf("%d", &x);
        a[i+n] = x - a[i];
        a[i] -= x;
        id[i] = i;
        id[i+n] = i+n;
    }
    sort(id+1,id+n+n+1,[](int x, int y) {
        return a[x] > a[y] || (a[x] == a[y] && (keep(x) > keep(y)||(keep(x) == keep(y) && x > y)));
    });
    long long ans = 0;
    for (int i= 1; i <= n + n; i ++)
        if (id[i] <= n)
            ins(id[i]);
        else
            ans += get(id[i] - n - 1);
    printf("%lld\n", ans);
    return 0;
}