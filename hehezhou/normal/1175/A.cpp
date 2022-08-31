#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, k, ans = 0;
        cin >> n >> k;
        while(n) {
            ans += n % k;
            n -= n % k;
            if(n) ans++, n /= k;
        }
        cout << ans << endl;
    }
    return 0;
}