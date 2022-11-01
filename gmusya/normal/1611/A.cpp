#include <iostream>

using namespace std;

int first_digit(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

bool even_digit(int n) {
    while (n) {
        if (n % 2 == 0) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (!even_digit(n)) {
            cout << -1 << '\n';
        } else if (n % 2 == 0) {
            cout << 0 << '\n';
        } else if (first_digit(n) % 2 == 0) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}