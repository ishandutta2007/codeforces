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

vector <int> E[N], e[N], ans;
int v[N], c[N], s[N];



void Dfs(int x){
    v[x] = 1;
    s[x] = c[x];
    for (int i = 0; i < E[x].size(); i++)
    if (!v[E[x][i]]){
        e[x].PB(E[x][i]);
        e[E[x][i]].PB(x);
        Dfs(E[x][i]);
        s[x] += s[E[x][i]];
    }
}

void Solve(int x, int par){
    v[x] = 1;
    for (int i = 0; i < e[x].size(); i++){
        int y = e[x][i];
        if (!v[y] && s[y] - c[y] > 0){
            ans.PB(y);
            c[y] ^= 1;
            Solve(y, x);
            ans.PB(x);
            c[x] ^= 1;
        }
        if (y != par && c[y]){
            ans.PB(y);
            c[y] ^= 1;
            v[y] = 1;
            ans.PB(x);
            c[x] ^= 1;
        }
    }
}

int main(){
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        E[x].PB(y);
        E[y].PB(x);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    int t, cnt = 0;
    for (int i = 1; i <= n; i++)
    if (!v[i]){
        Dfs(i);
        if (s[i] > 0){
            cnt++;
            t = i;
        }
    }
    if (cnt == 0) puts("0"); else if (cnt > 1) puts("-1");
    else{
        memset(v, 0, sizeof(v));
        ans.PB(t);
        c[t] ^= 1;
        Solve(t, 0);
        int flag = 0;
        for (int i = 1; i <= n; i++) if (!v[i] && c[i]) flag = 1;
        if (flag) puts("-1"); else{
            n = ans.size();
            if (c[t]) n--;
            cout << n << endl;
            for (int i = 0; i < n; i++) printf("%d ", ans[i]);
        }
    }
}