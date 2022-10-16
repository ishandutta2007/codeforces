#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 100000;

int f[1 + MAXN], g[1 + MAXN], h[1 + MAXN];
vector<int> v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
        v[f[i]].push_back(i);
    }
    int m = 0;
    for (int i = 1; i <= n; i++)
        if (v[i].size()) {
            m++;
            bool ok = false;
            for (auto &it : v[i]) {
                g[it] = m;
                if (it == i)
                    ok = true;
            }
            if (!ok) {
                printf("-1\n");
                return 0;
            }
            h[m] = i;
        }
    printf("%d\n", m);
    for (int i = 1; i <= n; i++)
        printf("%d ", g[i]);
    printf("\n");
    for (int i = 1; i <= m; i++)
        printf("%d ", h[i]);
    printf("\n");
    return 0;
}