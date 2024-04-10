#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n > a * b) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            int x = i * b + (i % 2 ? j : b - j - 1);
            if (x >= n) x = -1;
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}