#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if((c + a - 1) / c + (d + b - 1) / d > k) cout << "-1\n";
        else cout << (c + a - 1) / c << ' ' << (d + b - 1) / d << endl;
    }
}