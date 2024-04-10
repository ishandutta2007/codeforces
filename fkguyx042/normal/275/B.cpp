#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std;  
int map[55][55], n, m;  
char s[55][55];  
const int d[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};  
bool inMap(int x, int y){  
    return x >= 0 && x < n && y >= 0 && y < m;  
}  
void dfs(int x, int y, int dir, int chg, int state){  
    map[x][y] = state;  
    for (int i = 0; i < 4; i++){  
        int xx = x + d[i][0];  
        int yy = y + d[i][1];  
        if (!inMap(xx, yy) || s[xx][yy] == 'W' || map[xx][yy] == state) continue;  
        if (i != dir && chg == 0) dfs(xx, yy, i, chg + 1, state);  
        else if (i == dir) dfs(xx, yy, i, chg, state);  
    }  
}  
int main(){  
    cin >> n >> m;  
    for (int i = 0; i < n; i++) cin >> s[i];  
    for (int i = 0; i < n; i++)  
      for (int j = 0; j < m; j++){  
          if (s[i][j] == 'B'){  
              memset(map, 0, sizeof(map));  
              for (int k = 0; k < 4; k++) dfs(i, j, k, 0, k + 1);  
              for (int k = 0; k < n; k++)  
                for (int l = 0; l < m; l++)  
                  if (s[k][l] == 'B' && map[k][l] == 0){  
                      cout << "NO" << endl;  
                      return 0;  
                  }  
          }  
      }  
    cout << "YES" << endl;  
    return 0;  
}