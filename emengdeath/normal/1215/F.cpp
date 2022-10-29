#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;
int n, p, M, m;
const int N = 2000000;
vector<int>g[N];
int bel_cnt;
int dfn[N], low[N], stack[N], tot, instack[N], bel[N];
void dfs(int x) {
    low[x] = dfn[x] = ++tot;
    instack[stack[++stack[0]] = x] = 1;
    for (auto u:g[x])
        if (!dfn[u]) {
            dfs(u);
            low[x] = min(low[x], low[u]);
        }else
        if (instack[u])
            low[x] = min(low[x], dfn[u]);
    if (dfn[x] == low[x]) {
        ++ bel_cnt;
        do{
            bel[stack[stack[0]]] = bel_cnt;
            instack[stack[stack[0]--]] = 0;
        } while (stack[stack[0] + 1] != x);
    }
}
pair<bool, vector<bool> > solve(int n) {//xx,x+n(x=0~n-1)
    for (int i = 0; i < 2 * n; i ++) dfn[i] = low[i] = bel[i] = 0;
    tot = 0, bel_cnt = 0;
    for (int i = 0; i < 2 * n; i ++)
        if (!dfn[i])
            dfs(i);
    vector<bool> ans(n, 0);
    for (int i = 0; i < n; i ++)
        if (bel[i] == bel[i + n]) return make_pair(false, ans);
    for (int i = 0; i < n; i ++)
        if (bel[i] > bel[i + n])//ans[i]=1ii
            ans[i] = 1;
    return make_pair(true, ans);
}
namespace IO {
    const int BUF_SIZE = 1 << 15;
    char in_buf[BUF_SIZE], out_buf[BUF_SIZE];
    char *p_in_buf = in_buf + BUF_SIZE;
    char *p_out_buf = out_buf;
    inline char get_char() {
        if (p_in_buf == in_buf + BUF_SIZE) {
            fread(in_buf, 1, BUF_SIZE, stdin), p_in_buf = in_buf;
        }
        return *(p_in_buf++);
    }
    inline void put_char(char x) {
        if (p_out_buf == out_buf + BUF_SIZE) {
            fwrite(out_buf, 1, BUF_SIZE, stdout), p_out_buf = out_buf;
        }
        *(p_out_buf++) = x;
    }
    inline void flush() {
        if (p_out_buf != out_buf) {
            fwrite(out_buf, 1, p_out_buf - out_buf, stdout);p_out_buf = out_buf;
        }
    }
}
#define getchar() IO::get_char()
#define putchar(x) IO::put_char(x)
inline int getint() {
    int x = 0;
    char c = getchar();
    while (c <= 32) c = getchar();
    while (c > 32) x = x * 10 + c - 48, c = getchar();
    return x;
}
inline int getint(char &c) {
    int x = 0;
    c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}
template <class T>
inline void _putint(T x) {
    return x ? _putint(x / 10), putchar(48 + x % 10), void() : void();
}
template <class T>
inline void putint(T x) {
    return x == 0 ? putchar('0'), void() : _putint(x), void();
}
inline void getline(char *s) {
    char c = getchar();
    while (c == '\n') c = getchar();
    while (c != '\n') *(s++) = c, c = getchar();
    *s = 0;
}
int all;
int id(int x, int y, int sig) {
    if (x == 0) {
        return sig * all + y;
    } else
        return sig * all + p + (x - 1) * M + y;
}
int main() {
    n = getint(), p = getint(), M = getint(), m = getint();
    all = p + M + 1;
    while (n --) {
        int x = getint() - 1, y = getint() - 1;
        g[id(0, x, 1)].push_back(id(0, y, 0));
        g[id(0, y, 1)].push_back(id(0, x, 0));
    }
    for (int i = 0; i < p; i ++){
        int l = getint() - 1, r = getint() - 1 + 1;
        g[id(0, i, 0)].push_back(id(1, l, 0));
        g[id(1, l, 1)].push_back(id(0, i, 1));
        g[id(0, i, 0)].push_back(id(1, r, 1));
        g[id(1, r, 0)].push_back(id(0, i, 1));
    }
    while (m --) {
        int x = getint() - 1, y = getint() - 1;
        g[id(0, x, 0)].push_back(id(0, y, 1));
        g[id(0, y, 0)].push_back(id(0, x, 1));
    }
    for (int i = 0; i <= M - 1; i ++) {
        g[id(1, i + 1, 0)].push_back(id(1, i, 0));
        g[id(1, i, 1)].push_back(id(1, i + 1, 1));
    }
    g[id(1, 0, 1)].push_back(id(1, 0, 0));
    g[id(1, M, 0)].push_back(id(1, M, 1));
    pair<bool, vector<bool> > u = solve(all);
    if (!u.first){
        puts("-1");
        return 0;
    }
    vector<int>ans(0);
    for (int i = 0; i < p; i ++)
        if (u.second[i] == 0)
            ans.push_back(i + 1);
    int ansM = -1;
    for (int i = 1; i <= M; i ++)
        if (u.second[i + p] == 1) {
            ansM = i;
            break;
        }
    if (ansM == -1 || !ans.size()) {
        puts("-1");
        return 0;
    }
    printf("%d %d\n", ans.size(), ansM);
    for (auto u:ans)
        printf("%d ", u);
    return 0;
}