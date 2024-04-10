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
const long long INF = 1e16;
long long a[N];
long long n, t;
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) t += a[n] - a[i];
    if (t >= a[n]) cout << a[n] << endl;
    else{
        //printf("%d\n", a[n] + ((a[1] - t + a[1]) + n - 2) / (n - 1));
        long long ans = t + (a[n] - t) / (n - 1) * n;
        if ((a[n] - t) % (n - 1) != 0) ans += (a[n] - t) % (n - 1) + 1;
        //printf("%d\n", ans);
        cout << ans << endl;
    }
}