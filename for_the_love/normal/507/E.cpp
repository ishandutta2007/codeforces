#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Anode{
    int x, y, z;
} ans[N];
struct Edge{
    int y, next, z;
} e[N + N];
int tot, head[N], x[N], y[N], z[N], b[N], dp[N], from[N];

void Addedge(int x, int y, int z){
    e[++tot].y = y; e[tot].z = z; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].z = z; e[tot].next = head[y]; head[y] = tot;
}

map <PI, int> S;

queue <int> Q;
int v[N];
void Bfs(){
    memset(dp, 0x7f, sizeof(dp));
    Q.push(1); v[1] = 1; b[1] = 1; dp[1] = 0;
    while (!Q.empty()){
        int x = Q.front(); Q.pop();
        for (int p = head[x]; p != -1; p = e[p].next){
            int y = e[p].y;
            if (!v[y]){
                v[y] = 1;
                b[y] = b[x] + 1;
                Q.push(y);
            }
            if (b[y] == b[x] + 1){
                if (1 - e[p].z + dp[x] < dp[y]){
                    dp[y] = 1 - e[p].z + dp[x];
                    from[y] = x;
                }
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if (!m) return 0;
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        //x[i] = i + 1, y[i] = i + 2, z[i] = 1;
        Addedge(x[i], y[i], z[i]);
    }
    Bfs();



    int p = n, cnt = 0;
    while (p != 1){
        S[MP(p, from[p])] = 1;
        if (dp[from[p]] + 1 == dp[p]){
            ans[++cnt].x = from[p];
            ans[cnt].y = p;
            ans[cnt].z = 1;
        }
        p = from[p];
    }
    for (int i = 0; i < m; i++)
    if (z[i] == 1 && !S[MP(x[i], y[i])] && !S[MP(y[i], x[i])]){
        ans[++cnt].x = x[i];
        ans[cnt].y = y[i];
        ans[cnt].z = 0;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
}