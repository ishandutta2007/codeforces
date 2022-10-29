#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 44;


int s[N][N], n, m, q;
int b[N][N], sum[N][N], ans[N][N][N][N];

inline int lowbit(int x){return x & -x;}
bool c(int a, int b, int c, int d){
    return (sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1]) == 0;
}

void add(int x, int y){
    for (int i = x; i <= n; i += lowbit(i))
    for (int j = y; j <= m; j += lowbit(j))
        b[i][j] ++;
}
int Query(int x, int y){
    int ret = 0;
    for (int i = x; i; i -= lowbit(i))
    for (int j = y; j; j -= lowbit(j))
        ret += b[i][j];
    return ret;
}
char str[N];
int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++){
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++) s[i][j] = (str[j] == '1');
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + s[i][j];
    }
    for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--){
        memset(b, 0, sizeof(b));
        if (!s[i][j]) for (int x = n; x >= i; x--)
        for (int y = m; y >= j; y--)
        if (c(i, j, x, y)) add(x, y);
        for (int x = n; x >= i; x--)
        for (int y = m; y >= j; y--)
            ans[i][j][x][y] = ans[i + 1][j][x][y] + ans[i][j + 1][x][y] - ans[i + 1][j + 1][x][y] + Query(x, y);
    }
    while (q--){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", ans[a][b][c][d]);
    }
}