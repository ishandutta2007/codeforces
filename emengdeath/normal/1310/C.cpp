#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1011;
char s[N];
__int128 f[N][N];
int n, m;
int rk[N][N];
int canto[N];
long long k;
int tot;
struct node{
    int son[26];
    int sz, o;
}tri[N * N];
void ins(int s, char *S, int step) {
    tri[s].o ++;
    if (!step) return;
    if (!tri[s].son[S[0]])
        tri[s].son[S[0]] = ++tot;
    ins(tri[s].son[S[0]], S + 1, step - 1);
}
void work(int ss, int l, int r, int nowrk) {
    nowrk += tri[ss].o;
    for (int i = 0; i < s[r]; i ++)
        if (tri[ss].son[i])
            nowrk += tri[tri[ss].son[i]].sz;
    rk[l][r] = nowrk;
    if (r == n) return;
    work(tri[ss].son[s[r]], l, r + 1, nowrk);
}
void dfs(int s) {
    tri[s].sz = tri[s].o;
    for (int i = 0; i < 26; i ++)
    if (tri[s].son[i]){
        dfs(tri[s].son[i]);
        tri[s].sz += tri[tri[s].son[i]].sz;
    }
}
long long get(int mnrk) {
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= m; j++)
            f[j][i] = 0;
        canto[i] = n + 1;
        while (canto[i] - 1 >= i && rk[i][canto[i] - 1] >= mnrk) canto[i] --;
    }
    f[0][0] = 1;
    f[0][1] = -1;
    for (int i = 0; i <= m; i ++)
        for (int j = 0; j < n; j ++) {
            f[i][j + 1] += f[i][j];
            f[i][j] = min(f[i][j], (__int128) k);
            f[i + 1][canto[j + 1]] += f[i][j];
        }
    return min(f[m][n], (__int128) k);
}
int main() {
    scanf("%d %d %lld", &n, &m, &k);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
        s[i] -= 'a';
    for (int i= 1; i <= n; i ++)
        ins(0, s + i, n - i + 1);
    dfs(0);
    tri[0].o = 0;
    for (int i = 1; i <= n; i ++)
        work(0, i, i, 0);
    int l = 0, r = tri[0].sz, mid, v = 0;
    while (l <= r) {
        if (get(mid = (l + r) / 2) >= k)
            l = mid + 1, v = max(v, mid);
        else
            r = mid - 1;
    }
    for (int i= 1; i <= n; i ++)
        for (int j = i; j<= n ; j++)
            if (rk[i][j] == v) {
                for (int k = i; k <= j; k ++)
                    printf("%c", s[k] + 'a');
                return 0;
            }
    return 0;
}