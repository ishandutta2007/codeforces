#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        int x = 0;
        for (int i = 0; i < 30; i++) {
            int a = (1 << i) - x, b = a + (1 << (i + 1));
            cout << "? " << a << " " << b << endl;
            cin >> a;
            if (a == (1 << (i + 1))) x |= 1 << i;
        }
        cout << "! " << x << endl;
    }
    return 0;
}