#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bool fl = false;
        for (int j = 0; j <= 100; ++j) {
            for (int k = 0; k <= 100; ++k) {
                if (3 * j + 7 * k == x && fl == false) {
                    cout << "YES" << endl;
                    fl = true;
                }
            }
        }
        if (!fl) cout << "NO" << endl;
    }
}