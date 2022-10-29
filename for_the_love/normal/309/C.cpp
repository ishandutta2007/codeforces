#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 7;
int n, m, x, cnt[33], b[N];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        for (int j = 0; j < 30; j++)
        if (x >> j & 1) cnt[j]++;
    }
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    for (int j = b[i]; j < 30; j++)
    if (cnt[j]){
        cnt[j]--;
        ans++;
        for (int k = b[i]; k < j; k++) cnt[k]++;
        break;
    }
    printf("%d\n", ans);

}