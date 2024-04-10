#include <iostream>

using namespace std;

int main() {
    long long L, R;
    cin >> L >> R;
    for (int i = 60; i >= 0; --i) {
        long long Q = 1LL << i;
        if (L < Q && R >= Q) {
            cout << 2 * Q - 1 << '\n';
            return 0;
        }
        if (L >= Q) {
            L -= Q;
            R -= Q;
        }
    }
    cout << 0 << '\n';
    return 0;
}