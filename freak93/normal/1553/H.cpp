#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve(vector<int> &A, vector<int> &best, vector<int> &max, vector<int> &min, int K, int start) {
    if (K == 0) {
        best[start] = A.size();
        if (A[start] > 0)
            max[start] = min[start] = start;
        else {
            max[start] = -numeric_limits<int>::max() / 3;
            min[start] =  numeric_limits<int>::max() / 3;
        }
        return;
    }

    solve(A, best, max, min, K - 1, start);
    solve(A, best, max, min, K - 1, start + (1 << (K - 1)));

    int G = (1 << (K - 1));
    for (int i = 0; i < G; ++i) {
        best[start + i] = ::min(best[start + i], best[start + G + i]);
        best[start + G + i] = best[start + i];

        best[start + i] = ::min(best[start + i], min[start + G + i] - max[start + i]);
        best[start + G + i] = ::min(best[start + G + i], min[start + i] - max[start + G + i] + 2 * G);

        int m1 = max[start + i];
        int m2 = max[start + G + i];
        max[start + i] = ::max(m1, m2);
        max[start + G + i] = ::max(m1 + G, m2 - G);

        m1 = min[start + i];
        m2 = min[start + G + i];
        min[start + i] = ::min(m1, m2);
        min[start + G + i] = ::min(m1 + G, m2 - G);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;

    vector<int> A(1 << K, 0);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        A[x]++;
    }

    vector<int> B(1 << K), max = B, min = B;
    solve(A, B, max, min, K, 0);
    for (auto &x : B)
        cout << x << " ";
    cout << "\n";
}