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

char s[105][105];
int n, cnt, ans[105];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    if (s[i][j] == '.'){
        cnt++;
        ans[i] = j;
        break;
    }
    if (cnt == n){
        for (int i = 1; i <= n; i++) printf("%d %d\n", i, ans[i]);
        return 0;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    if (s[j][i] == '.'){
        cnt++;
        ans[i] = j;
        break;
    }
    if (cnt == n){
        for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i], i);
        return 0;
    }
    puts("-1");
}