#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


const int N = 111111;
vector <int> e[N];
int a[N], b[N], res[N], ans, found, n, d[N];
void Dfs(int x, int p){
    if (p > ans){
        found = 1;
        ans = p;
    }
    if (a[x] && d[a[x]] == 1 && !b[a[x]]) Dfs(a[x], p + 1);
    if (found) res[ans - p + 1] = x;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        d[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    if (b[i]){
        found = 0;
        Dfs(i, 1);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++) printf("%d ", res[i]);
}