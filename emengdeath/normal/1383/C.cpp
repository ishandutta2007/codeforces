#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 21;
int out_e[N], in_e[N];
bool is_dag[1<<N], bz[N];
int T, n, v;
char s[1000000], t[1000000];
void dfs(int x) {
    if (bz[x]) return;
    bz[x] = 1;
    v |= (1 << x);
    for (int i = 0; i < 20;i ++)
        if (((out_e[x]|in_e[x]) >> i) & 1)
            dfs(i);
}
int main() {
    scanf("%d", &T);
    while (T --) {
        memset(is_dag, 0 ,sizeof(is_dag));
        memset(out_e, 0 ,sizeof(out_e));
        memset(in_e, 0 ,sizeof(in_e));
        memset(bz, 0 ,sizeof(bz));
        scanf("%d", &n);
        scanf("%s", s);
        scanf("%s", t);
        for (int i = 0; i < n; i ++) {
            int x = s[i] - 'a', y = t[i] - 'a';
            if (x == y) continue;
            out_e[x] |= (1 << y);
            in_e[y] |= (1 << x);
        }
        is_dag[0] = 1;
        int ans = 0;
        for (int i = 1; i < (1 << 20); i ++)
            for (int j = 0; j < 20; j ++)
                if ((i >> j) & 1)
                    is_dag[i] |= (is_dag[i ^ (1 << j)] && !(in_e[j] & i));
        for (int i = 0; i < 20; i ++)
            if (!bz[i]) {
                v = 0;
                dfs(i);
                int x = 0;
                for (int j = v; j > 0; j = ((j - 1) & v))
                    if (is_dag[j])
                        x = max(x, __builtin_popcount(j));
                ans += __builtin_popcount(v)*2 - x - 1;
            }
        printf("%d\n", ans);
    }
    return 0;
}