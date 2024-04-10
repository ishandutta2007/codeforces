#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < 11; i++) {
            if (n < 111 || n % 11 == 0) break;
            n -= 111;
        }

        if (n % 11) cout << "nO";
        else cout << "yEs";
        cout << '\n';
    }
}