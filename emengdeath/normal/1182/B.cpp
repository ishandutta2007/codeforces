#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int N = 1e3;
char s[N][N];
int n, m, x, y, sum;
int b[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
    scanf("%d %d", &n, &m);
    for (int i =  1; i <= n ; i++)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= m ; j ++)
            if (s[i][j] == '*'){
                sum ++;
                if (s[i - 1][j] == '*' && s[i + 1][j] == '*' && s[i][j + 1] == '*' && s[i][j - 1] == '*')
                    x = i, y = j;
            }
    if (!x){
        printf("NO");
        return 0;
    }
    for (int i = 0; i < 4; i ++){
        int xx = x, yy = y;
        while (s[xx + b[i][0]][yy + b[i][1]] == '*'){
            xx += b[i][0];
            yy += b[i][1];
            sum --;
        }
    }
    sum == 1?printf("YES"):printf("NO");
    return 0;
}