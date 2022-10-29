#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int N = 1e4 + 10;
char tmp[21];
int f[2][N];
int n, x;
char s[N];
const int AC_N = 2e6;
const int AC_C = 9;
int cnt;
struct AC_machine {
    struct node {
        int son[AC_C];
        int match[AC_C];
        int fail;
        int all;
        void clear() {
            memset(son, 0, sizeof(son));
            memset(match, 0, sizeof(match));
            fail = 0;
            all = 0;
        }
    } tri[AC_N];
    int L;
    void init() {
        while (L)tri[L--].clear();
        tri[L].clear();
    }
    int ins(int s, char *s1, int len) {
        for (int i = 0; i < len; i++) {
            if (!tri[s].son[s1[i]])
                tri[s].son[s1[i]] = ++L;
            tri[tri[s].son[s1[i]]].all = tri[s].all + s1[i]+ 1;
            s = tri[s].son[s1[i]];
        }
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
                }
        }
        for (auto u:d)
            for (int i= 0; i < AC_C; i ++)
                tri[u].match[i] = (tri[u].son[i]? tri[u].son[i] : tri[tri[u].fail].match[i]);
    }
}T;
void dfs(int index, int y, bool have_err) {
    int all = 0;
    for (int i = index - 1; i >= 0 && !have_err; i--) {
        all += tmp[i] + 1;
        if ((all != x) && x % all == 0){
            have_err = 1;
        }
    }
    if (!y && !have_err) {
        T.ins(0, tmp, index);
        cnt += !have_err;
    }
    for (int i = 1; i <= y && i <= 9; i ++)
        tmp[index] = i - 1, dfs(index + 1, y - i, have_err);
}
int main() {
    scanf("%s", s + 1);
    scanf("%d", &x);
    n = strlen(s + 1);
    T.init();
    dfs(0, x, 0);
    T.build();
    bool bz = 0, bz1 = 1;
    for (int i = 0; i <= T.L; i ++)
        f[0][i] = f[1][i] = 1e9;
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++, swap(bz, bz1))
        for (int j = 0; j <= T.L; j ++)
            if (f[bz][j] != 1e9) {
                f[bz1][j] = min(f[bz1][j], f[bz][j] + 1);
                int y = T.tri[j].match[s[i] - '1'];
                if (T.tri[y].all != x || T.tri[y].all != x)
                    f[bz1][y] = min(f[bz1][y], f[bz][j]);
                f[bz][j] = 1e9;
            }
    int ans = 1e9;
    for (int i = 0; i <= T.L; i ++)
        ans = min(f[bz][i], ans);
    printf("%d\n", ans);
    return 0;
}