#include <fstream>
using namespace std;

int n,m,k,s=0,fx,fy;
char a[501][501],degr[501][501];

inline int check(int y, int x) {
    return x >= 0 && x < m && y >= 0 && y < n && a[y][x] == 'X';
}

void dfs(int y, int x) {
    if (!s) return;
    --s;
    a[y][x] = '.';
    if (check(y-1,x)) dfs(y-1,x);
    if (check(y+1,x)) dfs(y+1,x);
    if (check(y,x-1)) dfs(y,x-1);
    if (check(y,x+1)) dfs(y,x+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;++i) {
        scanf("%s",a[i]);
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                a[i][j] = 'X';
                ++s;
                fx = j;
                fy = i;
            }
        }
    }

    s -= k;
    dfs(fy, fx);

    for (int i = 0; i < n; ++i)
        printf("%s\n",a[i]);

    return 0;
}