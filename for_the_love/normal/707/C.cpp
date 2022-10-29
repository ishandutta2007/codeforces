#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    while (cin >> n) {
        if (n <= 2) {
            cout << "-1" << endl;
        } else if (n & 1) {
            long long ans = (n * n + 1) / 2;
            cout << ans - 1 << " " << ans << endl;
        } else {
            long long ans = (n * n / 2 + 2) / 2;
            cout << ans - 2 << " " << ans << endl;
        }
    }
}