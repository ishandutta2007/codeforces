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

int i, n, c1, c2, c3, ans, a[205], s[205], v[205][205];

void dfs(int i, int j){
    if (v[i][j]) return;
    v[i][j] = 1;
    ans = max(ans, s[2 * n - 1] - s[j] - s[j]);
    for (int k = 0; k <= n; k++){
        if (i >= k && j >= n - k) dfs(i - k + n - k, j - n + k + k);
        if (j >= k && i >= n - k) dfs(i - n + k + k ,j - k + n - k);
    }
}
int main(){
    scanf("%d", &n);
    for (i = 1; i <= 2 * n - 1; i++) scanf("%d", &a[i]);
    for (i = 1; i <= 2 * n - 1; i++){
        if (!a[i]) c1++;
        if (a[i] > 0) c2++;
        if (a[i] < 0) c3++;
        a[i] = abs(a[i]);
    }
    sort(a + 1, a + 2 * n);
    for (i = 1; i <= 2 * n - 1; i++) s[i] = s[i - 1] + a[i];
    ans = -1e9;
    for (i = 0; i <= c1; i++){
        memset(v, 0, sizeof(v));
        dfs(c2 + i, c3 + c1 - i);
    }
    printf("%d\n", ans);
}