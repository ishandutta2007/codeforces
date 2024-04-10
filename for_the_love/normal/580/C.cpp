#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
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
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

vector <int> e[N];

int a[N], ans, n, m, x, y;

void dfs(int x, int par, int cnt){
    if (a[x] == 0) cnt = 0;
    else cnt++;
    if (cnt > m) return;
    if (x != 1 && e[x].size() == 1) ans++;
    for (int i = 0; i < e[x].size(); i++)
        if (e[x][i] != par)
            dfs(e[x][i], x, cnt);

}


int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    ans = 0;
    dfs(1, 0, 0);
    printf("%d\n", ans);

}