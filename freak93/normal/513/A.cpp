#include <iostream>

using namespace std;

int main() {
    int N1, N2, K1, K2; cin >> N1 >> N2 >> K1 >> K2;

    if (N1 <= N2)
        cout << "Second\n";
    else
        cout << "First\n";
}