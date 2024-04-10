#include <bits/stdc++.h>

using namespace std;


int main() {
    // ifstream cin("/home/stefanb/work/platform/src/app/shm_clean/input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        if (m < n || (n % 2 == 0 && m % 2 == 1)) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            if (n == 1) {
                cout << m << "\n";
            } else if (n % 2 == 1) {
                for (int i = 1; i < n; i++) {
                    cout << "1 ";
                }
                cout << m - (n - 1) << "\n";
            } else {
                for (int i = 1; i < n - 1; i++) {
                    cout << "1 ";
                }
                int x = (m - (n - 2));
                assert(x > 0 && x % 2 == 0);
                cout << x / 2 << " " << x / 2 << "\n";
            }
        }
    }
    return 0;
}