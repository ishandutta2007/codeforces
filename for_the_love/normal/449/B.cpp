#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Heap{
    int x; LL d;
    Heap(){}
    Heap(int _x, LL _d){x = _x, d = _d;}
    bool operator < (const Heap &A) const{
        return A.d < d;
    }
} now;

priority_queue <Heap> Q;

struct Edge{
    int y, d, next;
} e[600050];

int v[N], tot, head[N], f[N];
LL d[N];

void Addedge(int x, int y, int d){
    e[++tot].y = y; e[tot].d = d; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].d = d; e[tot].next = head[y]; head[y] = tot;
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        Addedge(x, y, z);
    }
    for (int i = 1; i <= n; i++) d[i] = 1e18;
    int ans = 0;
    for (int i = 0; i < k; i++){
        int x; LL y;
        scanf("%d%I64d", &x, &y);
        if (d[x] != 1e18) ans++;
        d[x] = min(d[x], y);
        f[x] = 1;
    }
    for (int i = 2; i <= n; i++) if (f[i]) Q.push(Heap(i, d[i]));
    Q.push(Heap(1, 0));
    d[1] = 0;
    for (int i = 1; i <= n; i++){
        if (Q.empty()) break;
        while (1){
            now = Q.top(); Q.pop();
            if (!v[now.x]) break;
        }
        int x = now.x;
        v[x] = 1;
        for (int p = head[x]; p != -1; p = e[p].next)
        if (d[e[p].y] > d[x] + e[p].d){
            Q.push(Heap(e[p].y, d[x] + e[p].d));
            d[e[p].y] = d[x] + e[p].d;
            f[e[p].y] |= 2;
        }else if (d[e[p].y] == d[x] + e[p].d) f[e[p].y] |= 2;
    }
    for (int i = 2; i <= n; i++) if (f[i] == 3) ans++;
    printf("%d\n", ans);
}