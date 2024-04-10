#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#define id(x, y) ((x - 1) * m + y)
using namespace std;
const int N = 301;
int a[N][N], b[N][N];
int fa[N * N];
int n, m, Q;
struct node{
    int x, y, c;
    node(int x = 0, int y = 0, int c = 0) : x (x), y (y), c (c){}
}q[2001001];
vector<node> c[2001001], d[2001001];
int ans[2001001];
int getfa(int x) {return x == fa[x] ? x: fa[x] = getfa(fa[x]);}
int allv = 0;
int B[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
void combine(int x, int y) {
    x = getfa(x);
    y = getfa(y);
    if (x != y)
        fa[x] = y, allv --;
}
void merge(int x, int y) {
    for (int i = 0; i < 4; i ++) {
        int xx = B[i][0] + x, yy = B[i][1] + y;
        if (xx>0 && xx <= n && yy > 0 && yy <= m &&b[xx][yy] == b[x][y]) {
            combine(id(xx, yy) , id(x, y));
        }
    }
}
void work(vector<node>&a,int lst, bool direct, int sig){
    for (int i= 1; i <= n * m ; i ++)
        fa[i] = i;
    allv = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (b[i][j] == sig)
                merge(i, j), allv ++;
    for (auto u:a) {
        if (!direct) {
            if (u.c <= lst) {
                ans[u.c + 1] += allv, ans[lst + 1] -= allv;
            }
        }else {
            if (u.c >= lst) {
                ans[lst] += allv, ans[u.c] -= allv;
            }
        }
        if (b[u.x][u.y] != sig) allv ++;
        b[u.x][u.y] = sig;
        merge(u.x, u.y);
        lst = u.c;
    }
}
int main() {
//    freopen("input","r",stdin);
    scanf("%d %d %d", &n, &m, &Q);
    int mx = 0;
    int st = 1;
    for (int i= 1; i <= Q; i ++) {
        scanf("%d %d %d", &q[i].x, &q[i].y, &q[i].c);
        mx = max(mx, q[i].c);
        d[q[i].c].push_back(node(q[i].x, q[i].y, i));
        while (st <= q[i].c) {
            for (int i= 1; i <= n; i ++)
                for (int j = 1; j <= m; j ++)
                    b[i][j] = a[i][j];
            reverse(c[st].begin(), c[st].end());
            work(c[st], i, 0, st);
            c[st].clear();
            if (st != q[i].c)
                c[st].push_back(node(1, 1, i));
            st ++;
        }
        if (a[q[i].x][q[i].y] != q[i].c)
        c[a[q[i].x][q[i].y]].push_back(node(q[i].x, q[i].y, i - 1));
        a[q[i].x][q[i].y] = q[i].c;
    }
    memset(a, 0, sizeof(a));
    for (int i = 0; i <= mx;i ++)
        reverse(c[i].begin(), c[i].end());
    for (int i = 1; i <=Q; i ++) {
        if (i == 1 || q[i].c != q[i - 1].c) {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    b[i][j] = a[i][j];
            c[q[i].c].push_back(node(1, 1, d[q[i].c][d[q[i].c].size() - 1].c));
            d[q[i].c].push_back(node(1, 1, d[q[i].c][d[q[i].c].size() - 1].c+1));
            work(d[q[i].c], d[q[i].c][0].c - 1, 1, q[i].c);
        }
        a[q[i].x][q[i].y] = q[i].c;
    }
    st = 0;
    while (st <= mx) {
        for (int i= 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                b[i][j] = a[i][j];
        work(c[st], Q, 0, st);
        st ++;
    }
    for (int i = 1 ;i <= Q; i ++)
        printf("%d\n", ans[i] += ans[ i -1]);
    return 0;
}