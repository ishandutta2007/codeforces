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
const int N = 111111;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, cnt;
int main(){
    double s = 0, x;
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; i++){
        scanf("%lf", &x);
        if (x - int(x) < 1e-4) continue;
        s -= x - (int)x;
        cnt++;
    }
    double ans = INF;
    for (int i = max(0, cnt - n); i <= min(n, cnt); i++) ans = min(ans, fabs(s + i));
    printf("%.3lf\n", ans);
}