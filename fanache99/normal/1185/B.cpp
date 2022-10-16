// Example program
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        bool bad = false;
        int x = 0, y = 0;
        while (x < a.size()) {
            if (y >= b.size()) {
                bad = true;
                break;
            }
            if (a[x] != b[y]) {
                bad = true;
                break;
            }
            int x0 = x;
            while (x0 < a.size() && a[x0] == a[x])
                x0++;
            int y0 = y;
            while (y0 < b.size() && b[y0] == b[y])
                y0++;
            if (x0 - x > y0 - y) {
                bad = true;
                break;
            }
            x = x0;
            y = y0;
        }
        if (y < b.size())
            bad = true;
        if (bad)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}