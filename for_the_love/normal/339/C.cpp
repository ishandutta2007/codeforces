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


int f[1555][15][15], g[1555][15][15], d[1555][15][15];
int n, v[15];
void Dfs(int x, int y, int z){
    if (f[x][y][z] != -1) return;
    f[x][y][z] = 0;
    if (x >= n){
        f[x][y][z] = 1;
        return;
    }
    for (int i = y + 1; i <= 10; i++)
    if (v[i] && i != z){
        Dfs(x + 1, i - y, i);
        if (f[x + 1][i - y][i]){
            g[x][y][z] = i - y;
            d[x][y][z] = i;
            f[x][y][z] = 1;
        }
    }
}
void Print(int x, int y, int z){
    if (x >= n) return;
    printf("%d", y + g[x][y][z]);
    if (x == n) puts(""); else printf(" ");
    Print(x + 1, g[x][y][z], d[x][y][z]);
}
int main(){
    string s;
    cin >> s;
    cin >> n;
    for (int i = 0; i < s.size(); i++)
    if (s[i] == '1') v[i + 1] = 1;
    memset(f, -1, sizeof(f));
    Dfs(0, 0, 0);
    if (f[0][0][0]){
        puts("YES");
        Print(0, 0, 0);
        return 0;
    }
    puts("NO");
}