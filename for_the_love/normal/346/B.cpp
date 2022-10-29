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

char s1[111], s2[111], s3[111], t[111];
int f[111][111][111], next[111][111], from[111][111][111];

void Dfs(int cnt, int x, int y, int z){
    if (cnt ==  1){
        printf("%c", s1[x]);
        return;
    }
    z = from[x][y][z];
    for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++)
    if (s1[i] == s2[j] && f[i][j][z] + 1 == cnt){
        Dfs(cnt - 1, i, j, z);
        printf("%c", s1[x]);
        return;
    }
}
int main(){
    scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
    int n1 = strlen(s1 + 1);
    int n2 = strlen(s2 + 1);
    int n3 = strlen(s3 + 1);
    for (int i = 0; i < n3; i++){
        for (int j = 1; j <= i; j++) t[j] = s3[j];
        for (int j = 0; j < 26; j++){
            t[i + 1] = 'A' + j;
            for (int k = i + 1; k >= 0; k--){
                int flag = 1;
                for (int x = 0; x < k; x++) if (s3[k - x] != t[i + 1 - x]){
                    flag = 0;
                    break;
                }
                if (flag){
                    next[i][j] = k;
                    break;
                }
            }
        }

    }
    int ans = 0, x, y, z;
    for (int i = 0; i <= n1; i++)
    for (int j = 0; j <= n2; j++)
    for (int k = 0; k < n3; k++){
        if (i && j && s1[i] == s2[j] && next[k][s1[i] - 'A'] != n3 && f[i - 1][j - 1][k] + 1 > f[i][j][next[k][s1[i] - 'A']]){
            f[i][j][next[k][s1[i] - 'A']] = f[i - 1][j - 1][k] + 1;
            from[i][j][next[k][s1[i] - 'A']] = k;
            if (f[i][j][next[k][s1[i] - 'A']] > ans){
                x = i;
                y = j;
                z = next[k][s1[i] - 'A'];
                ans = f[i][j][next[k][s1[i] - 'A']];
            }
        }
        if (i && j) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k]);
        if (i) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
        if (j) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k]);
        //f[i][j][k] = max(f[i - 1][j - 1][k], max(f[i - 1][j][k], f[i][j - 1][k]));
        //ans = max(f[i][j][k], ans);

    }
    if (!ans) puts("0"); else{
        //printf("%d\n", ans);
        Dfs(ans, x, y, z);
    }
}