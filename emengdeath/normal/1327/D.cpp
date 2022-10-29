#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6;
vector<int> g;
int c[N], p[N], cc[N];
int n;
bool check(int x) {
    for (int i = 0; i < x; i ++) {
        bool sig = 1;
        for (int j = i; j < g.size(); j += x)
            if (g[j] != g[i]) {
                sig  = 0;
                break;
            }
        if (sig) return 1;
    }
    return 0;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            scanf("%d", &p[i]);
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &c[i]), cc[i] = c[i];
        }
        int ans = n;
        for (int i = 1; i <= n; i ++)
        if (c[i]){
            int x = i;
            g.clear();
            while (c[x]) {
                g.push_back(c[x]);
                c[x] = 0;
                x = p[x];
            }
            int v = g.size();
            for (int j = 1; 1ll * j * j <= g.size(); j ++)
                if (g.size() % j == 0) {
                    if (check(j)) {
                        v = j;
                        break;
                    }
                    if (check(g.size() / j)) {
                        v = min(v, (int)g.size() / j);
                    }
                }
            ans = min(ans, v);
        }
        printf("%d\n", ans);
    }
    return 0;
}