#include <iostream>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        for (int i = n - 1; i >= 1; i--)
            if (n - i < k)
                k -= (n - i);
            else {
                for (int j = 1; j < i; j++)
                    cout << "a";
                cout << "b";
                for (int j = i + 1; j < n - k + 1; j++)
                    cout << "a";
                cout << "b";
                for (int j = n - k + 2; j <= n; j++)
                    cout << "a";
                cout << "\n";
                break;
            }
    }
    return 0;
}