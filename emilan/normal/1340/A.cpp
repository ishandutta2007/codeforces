#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p = n + 1;
        bool ok = true;
        while (n--) {
            int x;
            cin >> x;
            if (p + 1 < x) ok = false;
            p = x;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}