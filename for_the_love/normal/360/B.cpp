//#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <cassert>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5555;
const int INF = 1e9 + 7;

long long n, m, f[N], a[N];

long long Calc(long long l){
    for (int i = 1; i <= n; i++) f[i] = i - 1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
    if (abs(a[i] - a[j]) <= l * (long long)(i - j)) f[i] = min(f[i], f[j] + i - j - 1);
    for (int i = 1; i < n; i++) f[n] = min(f[n], f[i] + n - i);
    return f[n];
}
int main(){
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1){
        puts("0");
        return 0;
    }
    long long l = 0, r = 2e9, ans;
    while (l <= r){
        int mid = l + r >> 1;
        if (Calc(mid) <= m){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }

    cout << ans << endl;
}