#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

vector <int> e[N];


int dfn[N], low[N], z[N], inz[N], v[N], c[N], top, tim;

LL cnt, ans;


void Calc(int x){
    int l = inz[x], mn = INF, num = 0;
    for (int i = l; i <= top; i++){
        inz[z[i]] = 0;
        if (mn == c[z[i]]) num++;
        else if (mn > c[z[i]]){
            mn = c[z[i]];
            num = 1;
        }
    }

    top = l - 1;
    ans += mn;
    cnt = cnt * num % MOD;
}

void Tarjan(int x){
    v[x] = 1;
    dfn[x] = low[x] = ++tim;
    z[++top] = x; inz[x] = top;

    for (int i = 0; i < e[x].size(); i++)
    if (!v[e[x][i]]){
        Tarjan(e[x][i]);
        low[x] = min(low[x], low[e[x][i]]);
    }else if (inz[e[x][i]]) low[x] = min(low[x], dfn[e[x][i]]);

    if (low[x] == dfn[x]) Calc(x);
}


int main(){
    int n, m, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        e[x].PB(y);
    }


    cnt = 1;

    for (int i = 1; i <= n; i++)
    if (!v[i]) Tarjan(i);


    cout << ans << " " << cnt << endl;

}