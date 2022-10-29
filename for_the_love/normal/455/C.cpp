#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};


int d[N], v[N], fa[N], mx[N], l[N], used[N];
queue <int> Q;

struct Edge{
    int y, next;
} e[N + N];

int tot, head[N];


inline int Min(int x, int y){return x < y ? x : y;}
inline int Max(int x, int y){return x > y ? x : y;}


void Addedge(int x, int y){
    e[++tot].y = y; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].next = head[y]; head[y] = tot;
}

int Bfs(int x, int y){
    Q.push(x); d[x] = 0;
    v[x]++;
    while (!Q.empty()){
        x = Q.front(); Q.pop();
        for (int p = head[x]; p != -1; p = e[p].next)
        if (v[e[p].y] == y){
            d[e[p].y] = d[x] + 1;
            v[e[p].y] ++;
            Q.push(e[p].y);
        }
    }
    return x;
}

int root(int x){if (fa[x] != x) fa[x] = root(fa[x]); return fa[x];}


void Get_Centrid(int x){
    x = Bfs(x, 0);
    int y = Bfs(x, 1);
    x = root(x);
    l[x] = d[y];
    mx[x] = (l[x] + 1) / 2;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n, m, q, x, y;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) fa[i] = i;
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        //x = i, y = i + 1;
        //fa[x] = y;
        //e[x].PB(y), e[y].PB(x);
        Addedge(x, y);
        x = root(x), y = root(y);
        fa[x] = y;
    }
    for (int i = 1; i <= n; i++)
    if (!v[root(i)]) Get_Centrid(i);

    //fclose(stdin);
    while (q--){
        int op;
        scanf("%d", &op);
        if (op == 1){
            scanf("%d", &x);
            printf("%d\n", l[root(x)]);
        }else{
            scanf("%d%d", &x, &y);
            x = root(x), y = root(y);
            if (x == y) continue;
            fa[x] = y, l[y] = Max(Max(l[y], l[x]), mx[x] + mx[y] + 1), mx[y] = Min(Max(mx[y], mx[x] + 1), Max(mx[x], mx[y] + 1));
        }
    }
}