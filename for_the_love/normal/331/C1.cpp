#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int f[1000005];

void dfs(int x){ 
    if (f[x] != -1) return;
    if (!x){
        f[x] = 0;
        return;
    }
    f[x] = 1e9 + 7;
    int y = x;
    while (y){
        dfs(x - y % 10);
        f[x] = min(f[x], f[x - y % 10] + 1);
        y = y / 10;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    memset(f, -1, sizeof(f));
    dfs(n);
    printf("%d\n", f[n]);
}