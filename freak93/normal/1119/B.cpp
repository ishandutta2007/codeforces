#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_fit(vector<int> A, int H) {
    sort(A.begin(), A.end());
    for (int i = A.size() - 1; i >= 0; i -= 2) {
        H -= A[i];
        if (H < 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int N, H; cin >> N >> H;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int step;
    for (step = 1; step < N; step <<= 1);
    int K;
    for (K = 0; step; step >>= 1)
        if (K + step <= N && can_fit(vector<int>(A.begin(), A.begin() + K + step), H))
            K += step;
    cout << K << "\n";
}