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

const int M = 100005;
int n, a, b, x[M], y[M];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &y[i]);
    }
    sort(y + 1, y + n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++)
    if (y[i] != y[i - 1]) x[++m] = y[i];
    n = m;
    //unique(a + 1, a + n + 1);
    scanf("%d%d", &a, &b);
    int ans = 0;
    while (b < a){
        int mx = 1;
        for (int i = 1; i <= n; i++)
        if (a - a % x[i] >= b){
            mx = max(mx, a % x[i]);
        }else{
            x[i] = x[n];
            n--;
            i--;
        }
        a -= mx;
        ans++;
    }
    printf("%d\n", ans);
}