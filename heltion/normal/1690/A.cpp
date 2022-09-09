#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        if (n % 3 == 0) cout << n / 3 << " " << n / 3 + 1 << " " << n / 3 - 1 << "\n";
        else if (n % 3 == 1) cout << n / 3 << " " << n / 3 + 2 << " " << n / 3 - 1 << "\n";
        else cout << n / 3 + 1 << " " << n / 3 + 2 << " " << n / 3 - 1 << "\n";
    }
    return 0;   
}