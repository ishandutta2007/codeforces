#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

int main() {
    cin >> n >> m;
    if (n <= m) {
        cout << n << endl;
        return 0;
    }
    n -= m;
    ll l = 0;
    l = (sqrt(1 + n * 8.0) - 1) / 2;
    while (l * (l + 1) / 2 < n)
        ++l;
    cout << m + l << endl;
    return 0;
}