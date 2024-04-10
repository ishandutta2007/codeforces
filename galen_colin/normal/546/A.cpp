#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll k, n, w;
    cin >> k >> n >> w;
    ll l = (w * (w+1)) / 2 * k;
    if (l > n) cout << l - n;
    else cout << 0;
    cout << endl;
}