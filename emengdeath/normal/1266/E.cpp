#include <string>
#include <cstdio>
#include <map>
using namespace std;
const int N = 2e5+10;
map<pair<int, int>, int>f;
int n;
int a[N], b[N];
long long ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++)
        scanf("%d", &a[i]), ans += a[i];
    int m;
    scanf("%d", &m);
    while (m --){
        int x, y, z;
        scanf("%d %d %d", &x ,&y, &z);
        int tmp = f[make_pair(x, y)];
        if (tmp) {
            if (b[tmp] <= a[tmp]) ans ++;
            b[tmp] --;
        }
        f[make_pair(x ,y)] = z;
        b[z] ++;
        if (b[z] <= a[z]) ans --;
        printf("%lld\n", ans);
    }
    return 0;
}