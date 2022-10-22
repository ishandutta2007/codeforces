#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int64_t total = 0;
        vector<int64_t> A(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
            total += A[i];
        }

        if (total % N) {
            cout << "-1\n";
            continue;
        }

        int64_t average = total / N;
        cout << 3 * (N - 1) << "\n";
        for (int i = 2; i <= N; ++i) {
            int64_t need = i - A[i] % i;
            if (need == i)
                need = 0;
            cout << 1 << " " << i << " " << need << "\n";
            A[i] += need;
            A[1] -= need;
            cout << i << " " << 1 << " " << A[i] / i << "\n";
            A[1] += A[i];
        }

        for (int i = 2; i <= N; ++i) {
            cout << 1 << " " << i << " " << average << "\n";
        }
    }
}