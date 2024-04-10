#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int kModulo = 1000000007;

int main() {
    int N; cin >> N;

    vector<int> have(N + 1, 0);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > 0)
            have[A[i]] = 1;

        if (A[i] == i + 1) {
            cout << "0\n";
            return 0;
        }
    }

    set<int> up;
    set<int> down;
    for (int i = 0; i < N; ++i)
        if (A[i] == -1)
            up.insert(i + 1);
    for (int i = 1; i <= N; ++i)
        if (not have[i])
            down.insert(i);

    int same = 0;
    for (auto &x : up)
        if (down.find(x) != down.end())
            ++same;

    N = up.size();
    vector<int> past(N + 1), present(N + 2, 0);
    present[0] = 1;
    for (int i = 1; i <= N; ++i) {
        swap(present, past);
        present = vector<int>(N + 2, 0);
        for (int j = 0; j <= N; ++j) {
            if (j > i) {
                present[j] = 0;
                continue;
            }

            int from = j;
            if (i <= same)
                from = j - 1;
            if (from >= 0)
                present[j] = (present[j] + past[from]) % kModulo;

            present[j] = (present[j] + 1LL * past[j] * (i - j - 1)) % kModulo;

            present[j] = (present[j] + 1LL * past[j + 1] * (j + 1)) % kModulo;
        }
    }

    cout << present[0] << "\n";
}