#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
long long calc(long long x, long long y) {
    return (y + x) * (y - x +1) / 2;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T -- ){
        long long n, m;
        cin>>n>>m;
        long long ans = 0;
        if (m * 2 >= n - (n & 1))  {
            ans += (n + 1) * n / 2 - n + m;
        } else {
            int tmp = (n - m) / (m + 1);
            ans = (n + 1) * n / 2;
            int x = (n  -m) % (m + 1);
            ans -= calc(1, tmp) * (m + 1 - x);
            ans -= calc(1, tmp + 1) * x;
        }
        cout<<ans << endl;
    }
}