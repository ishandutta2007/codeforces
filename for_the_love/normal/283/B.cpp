#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:36777216")
int n, i;
long long a[200010], f[200010][2];
int v[200010][2];
void dfs(int x, int p){
    if (f[x][p]) return;
    v[x][p] = 1;
    if (!p){
        if (x - a[x] <= 0){
            f[x][0] = a[x];
            v[x][p] = 0;
            return;
        }else if (x - a[x] == 1){
            f[x][0] = -1;
            v[x][p] = 0;
            return;
        }else{
            if (v[x - a[x]][1]){
                f[x][p] = -1;
                v[x][p] = 0;
                return;
            }
            dfs(x - a[x], 1);
            if (f[x - a[x]][1] == -1){
                f[x][0] = -1;
                v[x][p] = 0;
                return;
            }
            f[x][0] = a[x] + f[x - a[x]][1];
        }
    }
    if (p){
        if (x + a[x] > n){
            f[x][1] = a[x];
            v[x][p] = 0;
            return;
        }else{
            if (v[x + a[x]][0]){
                f[x][p] = -1;
                v[x][p] = 0;
                return;
            }
            dfs(x + a[x], 0);
            if (f[x + a[x]][0] == -1){
                f[x][1] = -1;
                v[x][p] = 0;
                return;
            }
            f[x][1] = a[x] + f[x + a[x]][0];
        }
    }
    v[x][p] = 0;
}
int main(){
    cin >> n;
    for (i = 2; i <= n; i++)
       cin >> a[i];
    for (i = 2; i <= n; i++){
        dfs(i, 0);
        dfs(i, 1);
    }
    for (i = 1; i < n; i++)
    if (f[i + 1][0] == -1) printf("-1\n"); else cout << f[i + 1][0] + i << endl;
}