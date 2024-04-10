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
const int INF = 1e9 + 7;
long long ans[105];
long long calc(long long n, long long t){
    long long l = 0, r = sqrt(n) + 100;
    while (l <= r){
        long long mid = (l + r) / 2;
        long long x = mid * 2 + 1;
        //long long tmp = n * 2 / x;
        double lim = (x - 1) * x / 2 + (double) t * x;
        if (n * 2 % x == 0 && x + 2 * t - 1 == 2 * n / x) return x;
        else if (lim < n) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main(){
    long long n, t = 1, cnt = 0;
    cin >> n;
    while (t - 1 <= n){
        long long tmp = calc(n, t - 1);
        if (tmp != -1) ans[++cnt] = tmp * t;
        t = t * 2;
    }
    sort(ans + 1, ans + cnt + 1);
    for (int i = 1; i <= cnt; i++) cout << ans[i] << endl;
    if (!cnt) puts("-1");
}