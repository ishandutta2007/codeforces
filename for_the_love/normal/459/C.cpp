#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
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
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

vector <int> ans[1005];
int a[1111], cnt, n, k, d;

bool check(int n, int k, int d){
    LL s = 1;
    for (int i = 1; i <= d; i++){
        s *= k;
        if (s >= n) return 1;
    }
    if (s >= n) return 1;
    return 0;
}
void Dfs(int x){
    if (cnt == n) return;
    if (x == d){
        for (int i = 0; i < d; i++) ans[i].PB(a[i]);
        cnt++;
        return;
    }
    for (int i = 1; i <= k; i++){
        a[x] = i;
        Dfs(x + 1);
        if (cnt == n) return;
    }
}
int main(){
    scanf("%d%d%d", &n, &k, &d);
    if (!check(n, k, d)){
        puts("-1");
        return 0;
    }
    cnt = 0;
    Dfs(0);
    for (int i = 0; i < d; i++){
        for (int j = 0; j < n; j++) printf("%d ", ans[i][j]); puts("");
    }
}