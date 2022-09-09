#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        LL a, b, x;
        cin >> a >> b >> x;
        int ok = 0;
        while (a and b) {
            if (a < b) swap(a, b);
            if (x <= a and (a - x) % b == 0) ok = 1;
            a %= b;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}