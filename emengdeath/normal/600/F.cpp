#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 2e3 + 10;
struct node{
    int to, eid;
}g[N][N];
int n, m, a, b;
int e[N * N][2], ans[N* N];
int mx;
void add(int x, int id, int to, int eid) {
    g[x][id].eid = eid;
    g[x][id].to = to;
    mx = max(id, mx);
    ans[eid] = id;
}
int main() {
    scanf("%d %d %d", &a, &b, &m);
    for (int i= 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[i][0] = x;
        e[i][1] = y + a;
    }
    mx = -1;
    n = a + b;
    for (int i = 1; i <= m; i ++) {
        int x = e[i][0], y = e[i][1];
        int c1 = 0;
        int c2 = 0;
        while (g[x][c1].to) c1 ++;
        while (g[y][c2].to) c2 ++;
        add(x, c1, y, i);
        int lastid = i;
        while (g[y][c1].to && g[y][c1].to != x) {
            int z = g[y][c1].to, eid = g[y][c1].eid;
            add(y, c1, x, lastid);
            add(y, c2, z, lastid = eid);
            g[z][c1].to = 0;
            x = y, y = z;
            swap(c1, c2);
        }
        add(y, c1, x, lastid);
    }
    printf("%d\n", mx + 1);
    for (int i = 1;  i<= m; i ++)
        printf("%d%c", ans[i] + 1, " \n"[i == m]);
    return 0;
}