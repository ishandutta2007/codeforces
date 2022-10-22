#include <iostream>
#include <vector>

using namespace std;

bool prime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        vector<int> A(N);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            sum += A[i];
        }

        if (!prime(sum)) {
            cout << N << "\n";
            for (int i = 1; i <= N; ++i)
                cout << i << " ";
            cout << "\n";
            continue;
        }

        int p = -1;
        for (int i = 0; i < N; ++i)
            if (A[i] % 2) {
                p = i;
                break;
            }

        cout << N - 1 << "\n";
        for (int i = 0; i < N; ++i)
            if (i != p)
                cout << i + 1 << " ";
        cout << "\n";
    }
}