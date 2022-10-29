#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
using namespace std;
int n;
pair<int, int> fa[1000][1000];
int ans[1000][1000], ans1[1000][1000];
pair<int, int> getfa(int x, int y) {
    if (fa[x][y] == make_pair(x, y)) return fa[x][y];
    return fa[x][y] = getfa(fa[x][y].first, fa[x][y].second);
}
void combine(int x ,int y, int xx , int yy) {
    pair<int, int> u = getfa(x, y);
    pair<int, int> v = getfa(xx, yy);
    if (u != v)
        fa[u.first][u.second] = v;
    if (x > n) x -= n, y -= n;
    else
        x += n, y += n;
    if (xx > n) xx -= n , yy -=n;
    else
        xx += n, yy += n;
    u = getfa(x, y);
    v = getfa(xx, yy);
    if (u != v)
        fa[u.first][u.second] = v;
}
void quest(int x, int y, int xx, int yy) {
    if (y > yy) swap(y, yy), swap(x, xx);
    if (x > xx) swap(x, xx), swap(y, yy);
    printf("? %d %d %d %d\n", x, y, xx, yy);
    fflush(stdout);
}
int main() {
  //  freopen("input","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        for (int j = 1;  j<=n ; j ++)
            fa[i][j] = make_pair(i, j), fa[i+n][j+n] = make_pair(i+n, j+n);
    for (int i = 1; i <= n; i ++)
        for (int j= 1; j <= n ; j ++) {
            if (j == 3 && i == 2) {
                quest(i, j, i - 1, j - 1);
                int sig;
                scanf("%d", &sig);
                if (sig == 1)
                    combine(i, j, i - 1, j - 1);
                else
                    combine(i + n, j + n, i - 1, j - 1);

            }
            if (j - 2 >= 1) {
                quest(i, j, i, j - 2);
                int sig;
                scanf("%d", &sig);
                if (sig == 1)
                    combine(i, j, i, j - 2);
                else
                    combine(i + n, j + n, i, j - 2);
            } else if (i - 2 >= 1) {
                quest(i, j, i - 2, j);
                int sig;
                scanf("%d", &sig);
                if (sig == 1)
                    combine(i, j, i - 2, j);
                else
                    combine(i + n, j + n, i - 2, j);


            } else if (i >= 2 && j >= 2) {
                quest(i, j, i - 1, j - 1);
                int sig;
                scanf("%d", &sig);
                if (sig == 1)
                    combine(i, j, i - 1, j - 1);
                else
                    combine(i + n, j + n, i - 1, j - 1);
            }
        }
    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= n; j ++) {
            if (getfa(i, j) == getfa(1, 1) || getfa(i, j) == getfa(1, 2))
                ans[i][j] = 1;

            if (getfa(i, j) == getfa(1, 1) || getfa(i, j) == getfa(1 +n, 2 +n))
                ans1[i][j] = 1;
        }
    int sig = 0;
    for (int i = 1; i <=n && !sig; i ++)
        for (int j = 1; j <= n &&!sig; j++)
            if (i + 2 <= n && j + 1 <= n) {
                if ((ans[i][j] == ans[i+2][j + 1] && (ans[i+1][j] == ans[i+2][j] || ans[i][j + 1] == ans[i+1][j+1])) !=(ans1[i][j] == ans1[i+2][j + 1] && (ans1[i+1][j] == ans1[i+2][j] || ans1[i][j + 1] == ans1[i+1][j+1])) ) {
                    quest(i, j, i + 2, j+1);
                    int x;
                    scanf("%d", &x);
                    sig = (x ==(ans[i][j] == ans[i+2][j + 1] && (ans[i+1][j] == ans[i+2][j] || ans[i][j + 1] == ans[i+1][j+1])) ) + 1;
                }
            } else
                if (i + 1 <= n && j + 2 <= n) {
                    if ((ans[i][j] == ans[i+1][j + 2] && (ans[i+1][j] == ans[i+1][j+1] || ans[i][j + 1] == ans[i][j+2]))!=(ans1[i][j] == ans1[i+1][j + 2] && (ans1[i+1][j] == ans1[i+1][j+1] || ans1[i][j + 1] == ans1[i][j+2]))) {
                        quest(i, j, i + 1, j + 2);
                        int x;
                        scanf("%d", &x);
                        sig = (x == (ans[i][j] == ans[i+1][j + 2] && (ans[i+1][j] == ans[i+1][j+1] || ans[i][j + 1] == ans[i][j+2]))) + 1;
                    }
                }
    if (sig == 1) {
        for (int i = 1; i <= n ; i++)
            for (int j = 1; j <= n; j ++)
                if ((getfa(i, j) == getfa(1, 1) || getfa(i, j) == getfa(1 + n, 2 + n)))
                    ans[i][j] = 1;
                else
                    ans[i][j] = 0;
    }
    printf("!\n");
    for (int i = 1; i <= n ; i ++) {
        for (int j = 1; j <= n; j++)
                printf("%d", ans[i][j]);
        printf("\n");
    }
    fflush(stdout);
    return 0;
}