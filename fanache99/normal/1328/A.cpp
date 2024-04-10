#include <iostream>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int a, b;
        cin >> a >> b;
        a %= b;
        if (a != 0)
            a = b - a;
        cout << a << "\n";
    }
    return 0;
}