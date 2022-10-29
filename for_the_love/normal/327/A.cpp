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

int n, i, j, k, sum, ans, a[105], b[105];
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++){
        for (k = 1; k <= n; k++) b[k] = a[k];
        for (k = i; k <= j; k++) b[k] = 1 - b[k];
        int sum = 0;
        for (k = 1; k <= n; k++)
            sum += b[k];
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
}