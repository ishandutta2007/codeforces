#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) cout << 3;
    else if (n == 2) cout << 5;
    else if (n == 3) cout << 7;
    else if (n % 3 == 1) cout << n / 3 * 4 + 4;
    else if (n % 3 == 2) cout << n / 3 * 4 + 5;
    else cout << n / 3 * 4 + 3;
}