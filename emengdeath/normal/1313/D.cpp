#include <algorithm>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, m, k;
int sig[10], bits[1 << 8];
map<int, pair<vector<int>, vector<int> > >  a;
int f[1<<8], g[1<<8];
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i < (1 << k); i ++)
        bits[i] = bits[i >> 1 ] + (i & 1);

    int last = 1e9;
    for (int i = 1; i <= n;  i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        a[l].first.push_back(i);
        a[r].second.push_back(i);
        last = min(l - 1, last);
    }
    f[0] = 1;
    for (auto u:a) {
        for (int i = 0; i < (1 << k); i ++)
            if (f[i])
                f[i] = f[i] + (bits[i] & 1) * (u.first - last);
        for (auto v:u.second.first)
            for (int i = 0; i < k; i ++)
                if (!sig[i]) {
                    sig[i] = v;
                    memcpy(g, f, sizeof(f));
                    memset(f, 0, sizeof(f));
                    for (int j = 0; j < (1 << k); j ++)
                        if (g[j]) {
                            f[j] = max(f[j], g[j]);
                            f[j + (1 << i)] = max(f[j + (1 << i)], g[j] + ((bits[j + (1 << i)] & 1) * 2 - 1));
                        }
                    break;
                }
        int mask = (1 << k) - 1;
        for (auto v:u.second.second)
            for (int i = 0; i < k ; i ++)
                if (sig[i] == v) {
                    mask ^= (1 << i);
                    sig[i] = 0;
                    break;
                }
        memcpy(g, f, sizeof(f));
        memset(f, 0, sizeof(f));

        for (int i = 0; i < (1 << k) ; i ++)
            if (g[i])
                f[i&mask] = max(f[i&mask], g[i]);
        last = u.first;
    }
    int ans = 0;
    for (int i = 0; i < (1 << k); i ++)
        ans = max(ans, f[i]);
    printf("%d\n", ans - 1);
    return 0;
}