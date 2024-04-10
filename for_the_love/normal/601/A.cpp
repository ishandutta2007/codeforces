#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 405 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, x, y, d[N], v[N], e[N][N];
queue <int> Q;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        e[x][y] = e[y][x] = 1;
    }
    Q.push(1);
    v[1] = 1; d[1] = 0;
    while (!Q.empty()){
        int x = Q.front(); Q.pop();
        for (int i = 1; i <= n; i++)
        if (e[x][i] != e[1][n] && !v[i]){
            v[i] = 1;
            d[i] = d[x] + 1;
            Q.push(i);
        }
    }
    if (d[n] == 0) puts("-1");
    else  printf("%d\n", d[n]);
}