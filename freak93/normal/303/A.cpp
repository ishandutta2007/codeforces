#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;

    if (N % 2 == 0) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < N; ++i)
        cout << i << " ";
    cout << "\n";
    for (int i = 0; i < N; ++i)
        cout << (i + 1) % N << " ";
    cout << "\n";

    for (int i = 0; i < N; ++i)
        cout << (2 * i + 1) % N << " ";
    cout << "\n";
}