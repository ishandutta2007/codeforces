#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <utility>

using namespace std;

template<class It>
int64_t divide(It begin, It end, const vector<int64_t> &best) {
    int K = best.size() - 1;
    if (end - begin == 1) {
        int64_t answer = 0;
        auto &now = *begin;
        for (int i = 0; i < int(now.size()); ++i)
            answer = max(answer, now[i] + best[K - i]);
        return answer;
    }

    vector<int64_t> aux = best;
    auto mid = (end - begin) / 2 + begin;
    for (auto it = begin; it != mid; ++it) {
        auto &now = *it;
        int L = now.size() - 1;
        for (int i = K - L; i >= 0; --i)
            aux[i + L] = max(aux[i + L], aux[i] + now[L]);
    }
    int64_t answer = divide(mid, end, aux);
    copy(best.begin(), best.end(), aux.begin());
    for (auto it = mid; it != end; ++it) {
        auto &now = *it;
        int L = now.size() - 1;
        for (int i = K - L; i >= 0; --i)
            aux[i + L] = max(aux[i + L], aux[i] + now[L]);
    }
    return max(answer, divide(begin, mid, aux));
}

int main() {
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;

    vector< vector<int64_t> > A(N);
    for (int i = 0; i < N; ++i) {
        int L; cin >> L;
        A[i].resize(L + 1, 0);
        for (int j = 1; j <= L; ++j) {
            cin >> A[i][j];
            A[i][j] += A[i][j - 1];
        }
        if (L > K)
            A[i].resize(K + 1);
    }

    vector<int64_t> best(K + 1, 0);
    cout << divide(A.begin(), A.end(), best) << "\n";
}