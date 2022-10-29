#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200001;
int n, m, k;
struct node{
    int sum[10][10];
    int tag;
    int lc, rc;
    void update(int v) {
        memset(sum, 0, sizeof(sum));
        tag = v;
        lc = rc = v - 1;
    }
}f[N * 4];
char S[N];
int dis[10][10];
void combine(int s) {
    for (int i = 0; i < 10; i ++)
        for (int j = 0; j < 10; j ++)
            f[s].sum[i][j] = f[s+s].sum[i][j] + f[s + s + 1].sum[i][j];
    f[s].lc = f[s+s].lc;
    f[s].rc = f[s+s+1].rc;
    f[s].sum[f[s+s].rc][f[s+s+1].lc] ++;
}
void build(int l, int r ,int s) {
    if (l == r) {
        f[s].lc = f[s].rc = S[l] - 'a';
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r)/ 2 + 1, r, s + s + 1);
    combine(s);
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        if (l!=r)
            f[s + s].update(f[s].tag), f[s+s+1].update(f[s].tag);
        f[s].tag = 0;
    }
}
void change(int l, int r, int s, int ll, int rr, int c) {
    down(l, r, s);
    if (rr < l || r < ll) return;
    if (ll <= l && r <= rr) {
        f[s].update(c + 1);
        return;
    }
    change(l, (l +r )/ 2, s + s, ll, rr,c );
    change((l + r) / 2 + 1, r, s + s + 1, ll, rr, c);
    combine(s);
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", S+ 1);
    build(1, n, 1);
    while (m --) {
        int sig;
        scanf("%d", &sig);
        if (sig == 1) {
            int l, r;
            char c;
            scanf("%d %d %c", &l, &r, &c);
            c -= 'a';
           change(1, n, 1, l, r, c);
        } else {
            scanf("%s", S);
            int ans = 0;
            for (int i = 0; i < k; i ++)
                S[i] -= 'a';
            for (int i = 0; i < k ; i ++)
                for (int j = 0; j < k; j ++)
                    if (i < j)
                        dis[S[i]][S[j]] = j - i;
                    else
                        dis[S[i]][S[j]] = j - i + k;
            int the_same = n - 1;
            for (int i = 0; i < k; i ++)
                for (int j = 0; j < k; j ++ )
                    if (i!=j)
                        the_same -= f[1].sum[i][j], ans += dis[i][j] * f[1].sum[i][j];
            ans += the_same * k;
            for (int i = 0; i < k; i ++) {
                if (S[i] == f[1].lc)
                    ans += i + 1;
            }
            printf("%d\n", (ans + k - 1) / k);
        }
    }
    return 0;
}