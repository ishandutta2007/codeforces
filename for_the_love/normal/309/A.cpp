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
long long n, l, t, a[N + N];


int Find(int l, int r){
    int x = a[l], ret;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[mid] - x <= t){
            l = mid + 1;
            ret = mid;
        }
        else r = mid - 1;
    }
    return ret;
}


int main(){
    cin >> n >> l >> t;
    t *= 2;
    double ans = n * (n - 1) / 2 * (t / l);
    t %= l;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i] + l;
    }
    for (int i = 1; i <= n; i++)
        ans += 0.5 * (Find(i, i + n - 1) - i);
    printf("%lf\n", ans / 2);
}