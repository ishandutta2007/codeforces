#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 301;
int n, k, T;
bool bz[N][N];
int a[N], b[N];
int main() {
    scanf("%d",&T);
    while (T --) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n ;j ++)
                bz[i][j] = 0, a[i] = b[i] = 0;
        priority_queue<pair<int, int> > q;
        for (int i = 1; i <= n; i ++)
        {
            q.push({k / n + (k % n >= i), i});
        }
        for (int i = 1; i <= n; i ++) {
            int cnt = k / n + (k % n >= i);
            vector<pair<int, int> >d;
            while (cnt --) {
                auto u = q.top();
                bz[i][u.second] = 1;
                u.first --;
                d.push_back(u);
                q.pop();
            }
            for (auto u:d)
                q.push(u);
        }
        for (int i= 1; i<= n; i ++)
            for (int j = 1; j <=n ; j ++)
                a[i] += bz[i][j], b[j] += bz[i][j];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        int ans = (a[n] - a[1]) * (a[n] - a[1]) + (b[n] - b[1]) * (b[n] - b[1]);
        printf("%d\n", ans);
        for (int i = 1; i <= n; i ++,puts(""))
            for (int j = 1; j <= n; j ++ )
                printf("%d", (int)bz[i][j]);
    }
    return 0;
}