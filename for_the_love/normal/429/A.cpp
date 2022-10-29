#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
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


int a[N], b[N];

vector <int> ans;
vector <int> e[N];
void Dfs(int x, int par, int p1, int p2, int dep){
    if (dep % 2 == 1){
        if (a[x] != b[x] && !p1){
            p1 = 1;
            ans.PB(x);
        }else if (a[x] == b[x] && p1) p1 = 0, ans.PB(x);
    }else{
        if (a[x] != b[x] && !p2) p2 = 1, ans.PB(x);
        else if (a[x] == b[x] && p2) p2 = 0, ans.PB(x);
    }
    for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != par) Dfs(e[x][i], x, p1, p2, dep + 1);
}


int main(){
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        e[x].PB(y);
        e[y].PB(x);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    Dfs(1, 0, 0, 0, 0);

    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
}