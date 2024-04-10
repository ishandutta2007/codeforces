#include <iostream>

using namespace std;

int main() {
    int64_t X, Y, M; cin >> X >> Y >> M;

    if (X > Y)
        swap(X, Y);

    if (Y >= M) {
        cout << "0\n";
        return 0;
    }


    if (X <= 0 and Y <= 0) {
        cout << "-1\n";
        return 0;
    }

    int64_t operations = 0;
    if (X < 0) {
        int64_t k = (-X - 1) / Y + 1;
        operations += k;
        X += k * Y;
    }

    while (max(X, Y) < M) {
        ++operations;

        if (X > Y)
            swap(X, Y);
        X = X + Y;
    }

    cout << operations << "\n";
}