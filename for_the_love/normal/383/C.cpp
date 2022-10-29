#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200050;

int b[2][N + 50], l[N], r[N], tot, a[N], p[N];
vector<int> e[N];

void Dfs(int x, int par, int op){
    p[x] = op;
    l[x] = ++tot;
    for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != par) Dfs(e[x][i], x, op ^ 1);
    r[x] = tot;
}
inline int lowbit(int x){return x & -x;}
void Add(int p, int x, int y){
    for (; x <= N; x += lowbit(x)) b[p][x] += y;
}
int Q(int p, int x){
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += b[p][x];
    return ret;
}
int Query(int p, int x){
    return Q(p, x) - Q(p, x - 1);
}
int main(){
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    Dfs(1, 0, 0);
    for (int i = 1; i <= m; i++){
        int op;
        scanf("%d", &op);
        if (op == 1){
            scanf("%d%d", &x, &y);
            Add(p[x], l[x], y);
            Add(p[x], r[x] + 1, -y);
            //for (int i = 1; i <= 5; i++) cout << Q(1, i) << " ";
            //cout << endl;
            Add(p[x] ^ 1, l[x], -y);
            Add(p[x] ^ 1, r[x] + 1, y);
            //cout << "!" << endl;
            //for (int j = 1; j <= n; j++)
            //    cout << Query(p[j], l[j]) << endl;
        }else{
            scanf("%d", &x);
            cout << Q(p[x], l[x]) + a[x] << endl;
        }
    }

}