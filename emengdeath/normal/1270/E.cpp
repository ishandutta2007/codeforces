#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
const int N = 1e4;
int n;
int a[N][2], A[2][2], mn[2];
vector<int>g;
void output(){
    printf("%d\n", g.size());
    for (auto u:g)
        printf("%d ", u);
    exit(0);
}
int main() {
    scanf("%d", &n);
    mn[0] = mn[1] = 1e9;
    for (int i = 1; i <= n ;i ++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        mn[0] = min(mn[0], a[i][0]);
        mn[1] = min(mn[1], a[i][1]);
    }
    for (int i = 1; i <= n; i ++) {
        a[i][0] -= mn[0];
        a[i][1] -= mn[1];
    }
    int gg = 0;
    for (int i = 1; i <= n; i ++)
        gg = __gcd(a[i][0], gg), gg = __gcd(a[i][1], gg);
    if (gg) {
        for (int i = 1;i <= n; i ++)
            a[i][0] /= gg, a[i][1] /= gg;
    }
    for (int i = 1; i <= n; i ++)
        A[a[i][0] & 1][a[i][1] & 1] ++;
    if ((A[0][0] + A[1][1]) && (A[0][1] + A[1][0])) {
        for (int i = 1; i <= n; i ++)
            if ((a[i][0]&1) + (a[i][1] & 1) == 1)
                g.push_back(i);
        output();
    }
    for (int i = 1; i <= n; i ++)
        if ((a[i][0]&1))
            g.push_back(i);
    output();
    return 0;
}