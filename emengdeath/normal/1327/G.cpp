#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n;
const int N = 1011;
char s[400010];
struct node1{
    int to;
    long long v;
}f[N];
long long ff[1<<14][N], g[1<<14][N];
vector<int> w[15];
namespace _AC_machine {
    const int AC_N = 1011;
    const int AC_C = 14;
#define AC_pre_match 0
    struct AC_machine {
        struct node {
            int son[AC_C];
#ifdef AC_pre_match
            int match[AC_C];
#endif
            int fail;
            long long v;
            void clear() {
                memset(son, 0, sizeof(son));
#ifdef AC_pre_match
                memset(match, 0, sizeof(match));
#endif
                v = fail = 0;
            }
        } tri[AC_N];
        int L;
        void init() {
            while (L)tri[L--].clear();
            tri[L].clear();
        }
        int ins(int s, char *s1, int len, int v) {
            for (int i = 0; i < len; i++) {
                if (!tri[s].son[s1[i] - 'a'])
                    tri[s].son[s1[i] - 'a'] = ++L;
                s = tri[s].son[s1[i] - 'a'];
            }
            tri[s].v+= v;
            return s;
        }
        int next(int x, int c) {
            while (x && !tri[x].son[c]) x = tri[x].fail;
            if (tri[x].son[c]) x = tri[x].son[c];
            return x;
        }
        void build() {
            vector<int>d;
            int x;
            d.push_back(0);
            for (int l = 0; l < d.size(); l ++) {
                if (d[l])
                    tri[d[l]].v += tri[tri[d[l]].fail].v;
                for (int i = 0; i < AC_C; i++)
                    if (x = tri[d[l]].son[i]) {
                        d.push_back(x);
                        tri[x].fail = next(tri[d[l]].fail, i);
                        if (tri[x].fail == x) tri[x].fail = 0;
                    }
            }
#ifdef AC_pre_match
            for (auto u:d)
                for (int i= 0; i < AC_C; i ++)
                    tri[u].match[i] = (tri[u].son[i]? tri[u].son[i] : tri[tri[u].fail].match[i]);
#endif
        }
    };
}
using namespace _AC_machine;
AC_machine T;

void update(int cnt) {
    for (auto i:w[cnt])
        for (int j = 0; j <= T.L; j ++)
            g[i][f[j].to] = max(ff[i][j] + f[j].v, g[i][f[j].to]);
    for (auto i:w[cnt])
        for (int j = 0; j <= T.L; j ++)
            ff[i][j] = g[i][j], g[i][j] = -1e18;
    for (int i = 0; i <= T.L; i ++)
        f[i].to = i, f[i].v  =0;
}
int main() {
    scanf("%d", &n);
    T.init();
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s);
        int x;
        scanf("%d", &x);
        T.ins(0, s, strlen(s), x);
    }
    T.build();
    scanf("%s", s);
    for (int i = 0; i <=T.L; i ++)
        f[i].to = i, f[i].v  =0;
    for (int i = 0; i < (1 << 14); i ++)
        for (int j = 0; j <=T.L; j ++)
            ff[i][j] = -1e18, g[i][j] = -1e18;
    ff[0][0] = 0;
    int len = strlen(s);
    for (int i = 0; i <(1<<14) ; i ++)
        w[__builtin_popcount(i)].push_back(i);
    int cnt = 0;
    for (int i = 0; i < len ; i ++)
        if (s[i] == '?') {
            update(cnt);
            for (auto i:w[cnt])
                for (int k = 0; k < 14; k ++)
                    if (!((i >> k) & 1))
                        for (int j = 0; j <=T.L; j ++){
                            g[i | (1 << k)][T.tri[j].match[k]] = max(ff[i][j] + T.tri[T.tri[j].match[k]].v, g[i | (1 << k)][T.tri[j].match[k]]);
                        }
            ++cnt;
            for (auto i:w[cnt])
                for (int j = 0; j <=T.L; j ++)
                    ff[i][j] = g[i][j], g[i][j] = -1e18;
        } else {
            char c = s[i] - 'a';
            for (int i = 0; i <=T.L; i ++)
            {
                f[i].to = T.tri[f[i].to].match[c];
                f[i].v += T.tri[f[i].to].v;
            }
        }
    update(cnt);
    long long ans = -1e18;
    for (auto u:w[cnt])
        for (int i = 0; i <= T.L; i ++)
            ans = max(ans, ff[u][i]);
    printf("%lld\n", ans);
    return 0;
}