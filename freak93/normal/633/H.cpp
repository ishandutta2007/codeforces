#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int kMaxN = 30 * 1000 + 5;
int fib[kMaxN];
int A[kMaxN], L[kMaxN], R[kMaxN];
int last[kMaxN], solved[kMaxN];
int answer[kMaxN];

int main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    fib[1] = fib[2] = 1 % M;
    for (int i = 3; i <= N; ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % M;

    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> L[i] >> R[i];
        --L[i];
    }

    for (int i = 0; i < Q; ++i)
        last[i] = -1, solved[i] = 0;

    vector< pair<int, int> > P;
    for (int i = 0; i < N; ++i)
        P.emplace_back(A[i], i);

    sort(P.begin(), P.end());
    for (auto &p : P) {
        int value = p.first;
        int mult = value % M;
        int index = p.second;

        for (int i = 0; i < Q; ++i)
            if (L[i] <= index && index < R[i] && last[i] != value) {
                last[i] = value;
                answer[i] = (answer[i] + mult * fib[++solved[i]]) % M;
            }
    }

    for (int i = 0; i < Q; ++i)
        cout << answer[i] << "\n";
}