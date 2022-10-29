#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
const int N = 15;
map<int, int> f;
int n;
long long all, sum[N];
vector<int> a[N];
pair<int, int> g[1 << N][N], d[N];
pair<bool, int> w[1 << N];
bool can[1 << N];
bool bz[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int k;
        scanf("%d", &k);
        while (k --) {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
            f[x] = i;
            sum[i] += x;
            all += x;
        }
    }
    if (all % n) {
        puts("No");
        return 0;
    }
    all /= n;
    for (int i = 0; i < n; i ++) {
        if (sum[i] == all) {
            can[1 << i] = 1;
            g[1 << i][i] = {a[i][0], i};
        }
        for (auto u:a[i]) {
            memset(bz, 0, sizeof(bz));
            int x = i, y = u, v = 0;
            bool sig = 1;
            while (1) {
                if (abs(all - (sum[x] - y)) > 1e9) {
                    sig = 0;
                    break;
                }
                int z = all - (sum[x] - y);
                if (f.find(z) == f.end()) {
                    sig = 0;
                    break;
                }
                int to = f[z];
                if (to == x) {
                    sig = 0;
                    break;
                }
                v |= (1 << x);
                d[to] = {z, x};
                if (bz[to]) {
                    if (to != i || u != z)
                        sig = 0;
                    break;
                }
                bz[x] = 1;
                x = to, y = z;
            }
            if (sig) {
                for (int i = 0; i < n; i ++)
                    g[v][i] = d[i];
                can[v] = 1;
            }
        }
    }
    w[0] = {1, 0};
    for (int i = 0; i < (1 << n);  i++)
        if (w[i].first) {
            int mask = (1 << n)  -i - 1;
            for (int j = mask; j; j = (j - 1) & mask)
                if (can[j])
                    w[i + j] = {1, i};
        }
    int x = (1 << n) - 1;
    if (!w[x].first) {
        puts("No");
        return 0;
    }
    puts("Yes");
    while (x) {
        int y = w[x].second;
        x -= y;
        for (int i = 0; i < n; i ++)
            if ((x & (1 <<i)))
                d[i] = g[x][i];
        x = y;
    }
    for (int i = 0; i < n; i ++)
        printf("%d %d\n", d[i].first, d[i].second + 1);
    return 0;
}