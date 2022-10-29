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
const int N = 2e3 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int d[N][N],  v[N], n, flag;
PI vec[N][N];
vector <int> e[N];

void Gao(int x, int par){
    v[x] = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    if (i != x && d[i][x] + d[x][par] == d[i][par]) vec[x][cnt++] = MP(d[i][x], i);
    sort(vec[x], vec[x] + cnt);
    for (int i = 0; i < cnt; i++)
    if (!v[vec[x][i].second]){
        Gao(vec[x][i].second, x);
        e[vec[x][i].second].PB(x);
        e[x].PB(vec[x][i].second);
    }
}
void Dfs(int x, int st, int dis, int par){
    if (d[x][st] != dis){
        flag = 0;
        return;
    }
    for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != par){
        Dfs(e[x][i], st, dis + d[x][e[x][i]], x);
        if (!flag) return;
    }
}

int In(){
    int res = 0, ch, flag = 0;
    if((ch = getchar()) == '-')
        flag = 1;
    else if(ch >= '0' && ch <= '9')
        res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    return flag ? -res : res;
}

int main(){
    int x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        d[i][j] = In();
    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
    if (d[i][j] != d[j][i]){
        puts("NO");
        return 0;
    }else if (!d[i][j]){
        puts("NO");
        return 0;
    }
    for (int i = 1; i <= n; i++) if (d[i][i]){
        puts("NO");
        return 0;
    }
    for (int i = 1; i <= n; i++) d[0][i] = d[i][0] = d[i][1];
    Gao(1, 0);
    flag = 1;
    for (int i = 1; i <= n; i++){
        Dfs(i, i, 0, 0);
        if (!flag) break;
    }
    if (flag) puts("YES"); else puts("NO");
}