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


int a[105][2], sg[105][4][4];



void Dfs(int l, int x, int y){
    if (sg[l][x][y] != -1) return;
    if (!l){
        sg[l][x][y] = 0;
        return;
    }
    if (l == 1 && (x | y) == 3){
        sg[l][x][y] = 0;
        return;
    }
    bool v[100] = {0};
    for (int i = 1; i <= l; i++)
    if (i == 1){
        if (!(x & 1)){
            Dfs(l - 1, 2, y);
            v[sg[l - 1][2][y]] = 1;
        }
        if (!(x & 2)){
            Dfs(l - 1, 1, y);
            v[sg[l - 1][1][y]] = 1;
        }
    }else if (i == l){
        if (!(y & 1)){
            Dfs(l - 1, x, 2);
            v[sg[l - 1][x][2]] = 1;
        }
        if (!(y & 2)){
            Dfs(l - 1, x, 1);
            v[sg[l - 1][x][1]] = 1;
        }
    }else{
        Dfs(i - 1, x, 2);
        Dfs(l - i, 2, y);
        v[sg[i - 1][x][2] ^ sg[l - i][2][y]] = 1;
        Dfs(i - 1, x, 1);
        Dfs(l - i, 1, y);
        v[sg[i - 1][x][1] ^ sg[l - i][1][y]] = 1;
    }
    for (int i = 0; i < 100; i++)
    if (!v[i]){
        sg[l][x][y] = i;
        break;
    }
}


int main(){
    int n, m, x, y, ans = 0;
    scanf("%d%d", &n, &m);
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++) a[i][0] = a[i][1] = 0;
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        y--;
        a[x][y] = 1;
        a[x][y ^ 1] = 1;
        a[x - 1][y ^ 1] = 1;
        a[x + 1][y ^ 1] = 1;
    }
    memset(sg, -1, sizeof(sg));
    for (int i = 1; i <= n; i++){
        if (!a[i][0] || !a[i][1]){
            int l = 0, r = 0, len = 0;
            l = a[i][0] + a[i][1] * 2;
            while (!a[i][0] || !a[i][1]){
                len++;
                i++;
            }
            i--;
            r = a[i][0] + a[i][1] * 2;
            Dfs(len, l, r);
            ans ^= sg[len][l][r];
        }
    }
    if (!ans) puts("LOSE"); else puts("WIN");
}