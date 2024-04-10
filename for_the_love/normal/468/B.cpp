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

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Edge{
    int y, next, b;
} e[N + N + N + N];

map <int, int> S;
int x[N], ans[N], tot, head[N], deg[N], n, found = 0;
void Addedge(int x, int y, int b){
    if (x == y || !x || !y) return;
    e[++tot].y = y; e[tot].b = b; e[tot].next = head[x]; head[x] = tot; deg[x] ++;
    e[++tot].y = x; e[tot].b = b; e[tot].next = head[y]; head[y] = tot; deg[y] ++;
}

void Dfs(int x, int y){
    for (int p = head[x]; p != -1; p = e[p].next)
    if (ans[e[p].y] == -1){
        if (!y) ans[x] = ans[e[p].y] = e[p].b;
        Dfs(e[p].y, y ^ 1);
    }
}

void Solve(){
    for (int i = 1; i <= n; i++)
    if (ans[i] == -1 && deg[i] == 0) return;
    for (int i = 1; i <= n; i++)
    if (ans[i] == -1 && deg[i] == 1) Dfs(i, 0);
    for (int i = 1; i <= n; i++)
    if (ans[i] == -1 && deg[i] == 2) Dfs(i, 0);
    for (int i = 1; i <= n; i++)
    if (ans[i] == -1) return;
    found = 1;
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}

int main(){
    int A, B;
    scanf("%d%d%d", &n, &A, &B);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x[i]);
        S[x[i]] = i;
    }
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++){
        Addedge(S[x[i]], S[A - x[i]], 0);
        Addedge(S[x[i]], S[B - x[i]], 1);
    }
    for (int i = 1; i <= n; i++) deg[i] /= 2;
    memset(ans, -1, sizeof(ans));
    Solve(); if (found) return 0;
    if (A % 2 == 0 && S[A / 2]){
        memset(ans, -1, sizeof(ans));
        ans[S[A / 2]] = 0;
        for (int p = head[S[A / 2]]; p != -1; p = e[p].next) deg[e[p].y]--;
        Solve(); if (found) return 0;
        for (int p = head[S[A / 2]]; p != -1; p = e[p].next) deg[e[p].y]++;
        if (B % 2 == 0 && S[B / 2]){
            memset(ans, -1, sizeof(ans));
            for (int p = head[S[A / 2]]; p != -1; p = e[p].next) deg[e[p].y]--;
            for (int p = head[S[B / 2]]; p != -1; p = e[p].next) deg[e[p].y]--;
            ans[S[A / 2]] = 0;
            ans[S[B / 2]] = 1;
            Solve();if (found) return 0;
            for (int p = head[S[A / 2]]; p != -1; p = e[p].next) deg[e[p].y]++;
            for (int p = head[S[B / 2]]; p != -1; p = e[p].next) deg[e[p].y]++;
        }
    }
    memset(ans, -1, sizeof(ans));
    if (B % 2 == 0 && S[B / 2]){
        for (int p = head[S[B / 2]]; p != -1; p = e[p].next) deg[e[p].y]--;
        ans[S[B / 2]] = 1;
        for (int p = head[S[B / 2]]; p != -1; p = e[p].next) deg[e[p].y]++;
        Solve();if (found) return 0;
    }
    puts("NO");
}