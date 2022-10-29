#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5005;

int cnt[N], r[N][N];
char s[N][N];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
    if (s[i][j] == '1') r[i][j] = r[i][j + 1] + 1; else r[i][j] = 0;
    int ans = 0;
    for (int i = 1; i <= m; i++){
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; j++) cnt[r[j][i]]++;
        int t = 0;
        for (int j = m; j >= 1; j--){
            t += cnt[j];
            ans = max(ans, j * t);
        }
    }
    printf("%d\n", ans);
}