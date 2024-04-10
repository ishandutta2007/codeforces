#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
const int N = 1e5+1;
int n;
int a[N][2], d[N];
int main() {
    scanf("%d", &n);
    if (n == 2 ){
        printf("YES");
        return 0;
    }
    for (int i = 1; i < n ; i ++){
        scanf("%d %d", &a[i][0], &a[i][1]);
        d[a[i][0]] ++;
        d[a[i][1]] ++;
    }
    for (int i = 1; i <= n ; i ++)
        if (d[i] == 2) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}