#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
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

int n, x;
vector <int> vec[N];
int a[N], t = 0, cnt = 0, ans[3][N];
void Dfs(int x){
    if (cnt == 3) return;
    if (x == 2001){
        for (int i = 1; i <= n; i++) ans[cnt][i] = a[i];
        cnt++;
        return;
    }
    if (!vec[x].size()) Dfs(x + 1);
    else if (vec[x].size() == 1){
        a[++t] = vec[x][0];
        Dfs(x + 1);
        t--;
    }else if (vec[x].size() == 2){
        a[++t] = vec[x][1];
        a[++t] = vec[x][0];
        Dfs(x + 1);
        t -= 2;
        a[++t] = vec[x][0];
        a[++t] = vec[x][1];
        Dfs(x + 1);
        t -= 2;
    }else if (vec[x].size() >= 3){
        a[++t] = vec[x][0];
        a[++t] = vec[x][1];
        a[++t] = vec[x][2];
        for (int i = 3; i < vec[x].size(); i++) a[++t] = vec[x][i];
        Dfs(x + 1);
        t -= vec[x].size();
        a[++t] = vec[x][1];
        a[++t] = vec[x][0];
        a[++t] = vec[x][2];
        for (int i = 3; i < vec[x].size(); i++) a[++t] = vec[x][i];
        Dfs(x + 1);
        t -= vec[x].size();
        a[++t] = vec[x][2];
        a[++t] = vec[x][1];
        a[++t] = vec[x][0];
        for (int i = 3; i < vec[x].size(); i++) a[++t] = vec[x][i];
        Dfs(x + 1);
        t -= vec[x].size();
    }
}


int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        vec[x].PB(i);
    }
    Dfs(0);
    if (cnt != 3) puts("NO");
    else{
        puts("YES");
        for (int i = 0; i < 3; i++){
            for (int j = 1; j <= n; j++) printf("%d ", ans[i][j]);
            puts("");
        }
    }
}