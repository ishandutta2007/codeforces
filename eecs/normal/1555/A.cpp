#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        long long m = max(6LL, (n + 1) / 2 * 2);
        cout << m / 2 * 5 << '\n';
    }
    return 0;
}