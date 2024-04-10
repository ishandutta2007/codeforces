#include <iostream>

using namespace std;

int main() {
    int N, M, A;
    cin >> N >> M >> A;

    cout << 1LL * ((N - 1) / A + 1) * ((M - 1) / A + 1);
}