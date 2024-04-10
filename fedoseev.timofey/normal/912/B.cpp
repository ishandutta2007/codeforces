#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    int mx = -1;
    for (int i = 0; i <= 62; ++i) {
        if (n & (1LL << i)) {
            mx = i;
        }
    }
    ll ans = n;
    --k;
    if (k == 0) {
        cout << ans << endl;
        return 0;
    }
    for (int i = mx; i >= 0; --i) {
        ans |= (1LL << i);
    }
    cout << ans << endl;
}