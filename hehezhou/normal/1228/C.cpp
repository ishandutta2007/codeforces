#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n, x;
long long ans = 1;
long long power(long long a, long long b) {
    long long res = a, ans = 1;
    for(; b; b >>= 1, res = res * res % mod) if(b & 1) ans = ans * res % mod;
    return ans;
}
int main() {
    cin >> x >> n;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            while(x % i == 0) x /= i;
            long long cnt = 0, tmp = n;
            while(tmp) cnt += tmp /= i;
            ans = ans * power(i, cnt) % mod;
        }
    }
    if(x != 1) {
        long long cnt = 0, tmp = n;
        while(tmp) cnt += tmp /= x;
        ans = ans * power(x, cnt) % mod;
    }
    return cout << ans << endl, 0;
}