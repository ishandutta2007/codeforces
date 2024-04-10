#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        vector<int64_t> partial(N, 0);
        for (int i = 0; i + 1 < N; ++i)
            if (A[i] < A[i + 1])
                partial[i + 1] += A[i + 1] - A[i];
            else {
                partial[0] += A[i] - A[i + 1];
                partial[i + 1] -= A[i] - A[i + 1];
            }
        for (int i = 1; i < N; ++i) {
            partial[i] += partial[i - 1];
        }
        bool good = true;
        for (int i = 0; i < N; ++i)
            if (partial[i] > A[i])
                good = false;
        if (good)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}