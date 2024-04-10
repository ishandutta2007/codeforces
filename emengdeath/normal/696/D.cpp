/**  
 * @title: a
 * @projectName acm
 * @description: preffix auto machine and 2-multiply
 * @author emengdeath
 * @date 2020/4/1014:39
 */
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
namespace _AC_machine {
    const int AC_N = 1e6;
    const int AC_C = 26;
#define AC_pre_match 0
    struct AC_machine {
        struct node {
            int son[AC_C];
#ifdef AC_pre_match
            int match[AC_C];
#endif
            int fail, v;
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
            tri[s].v += v;
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
                for (int i = 0; i < AC_C; i++)
                    if (x = tri[d[l]].son[i]) {
                        d.push_back(x);
                        tri[x].fail = next(tri[d[l]].fail, i);
                        if (tri[x].fail == x) tri[x].fail = 0;
                        else
                            tri[x].v += tri[tri[x].fail].v;
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
int n;
long long m;
const int N = 201;
long long a[N], b[N][N], c[N], d[N][N];
char s[N];
int v[N];
_AC_machine::AC_machine T;
int main() {
    scanf("%d %lld", &n, &m);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &v[i]);
    }
    T.init();
    for (int i = 0; i < n; i ++) {
        scanf("%s", s);
        T.ins(0, s, strlen(s), v[i]);
    }
    T.build();
    for (int i = 1; i <= T.L; i ++ )
        a[i] = -1e18;
    for (int j = 0; j <= T.L; j ++)
        for (int k = 0; k <= T.L; k ++)
            b[j][k] = -1e18;
    for (int i = 0; i <= T.L; i ++ ) {
        for (int j = 0; j < _AC_machine::AC_C ; j ++)
            b[i][T.tri[i].match[j]] = max(b[i][T.tri[i].match[j]], (long long)T.tri[T.tri[i].match[j]].v);
    }
    while (m) {
        if (m&1) {
            for (int i = 0; i <= T.L; i ++)
                c[i] = -1e18;
            for (int i = 0; i <= T.L; i ++)
                if (a[i] >= 0)
                for (int j = 0; j <= T.L; j ++)
                    if (b[i][j] >= 0)
                        c[j] = max(c[j], a[i] + b[i][j]);
            for (int i = 0; i <= T.L; i ++)
                a[i] = c[i];
        }
        for (int i = 0; i <= T.L;i ++)
            for (int j = 0; j <= T.L; j ++)
                d[i][j] = -1e18;
        for (int i = 0; i <= T.L; i ++)
            for (int j = 0; j <= T.L; j ++)
                if (b[i][j] >= 0)
                    for (int k = 0; k <= T.L; k ++)
                        if (b[j][k] >= 0)
                            d[i][k] = max(d[i][k], b[i][j] + b[j][k]);
        for (int i = 0; i <= T.L;i ++)
            for (int j = 0; j <= T.L; j ++)
                b[i][j] = d[i][j];
        m >>= 1;
    }
    long long ans  =0;
    for (int i = 0; i <= T.L; i ++)
        ans = max(ans, a[i]);
    printf("%lld\n", ans);
    return 0;
}