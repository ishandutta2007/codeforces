#include <bits/stdc++.h>
using namespace std;
int n1, n2, k1, k2, n;
int main() {
    cin >> n1 >> n2 >> k1 >> k2 >> n;
    int tmp = n;
    tmp -= n1 * (k1 - 1);
    tmp -= n2 * (k2 - 1);
    cout << max(tmp, 0) << ' ';
    int ans = 0;
    if(k1 < k2) {
        ans += min(n1, n / k1);
        n -= ans * k1;
        ans += min(n2, n / k2);
    }
    else {
        ans += min(n2, n / k2);
        n -= ans * k2;
        ans += min(n1, n / k1);
    }
    return cout << ans << endl, 0;
}