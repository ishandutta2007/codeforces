#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

static const int kLimit = 2000;

class FenwickTree {
  public:
    FenwickTree(int size): m_size(size), m_data(size, 0) {}

    void add(int x, int64_t y) {
        assert(x < m_size);
        for (++x; x <= m_size; x += (x & -x))
            m_data[x - 1] += y;
    }

    int64_t query(int x) {
        int64_t sum = 0;
        for (++x; x; x -= (x & -x))
            sum += m_data[x - 1];
        return sum;
    }

    int64_t query(int x, int y) {
        return query(y) - query(x - 1);
    }

  private:
    int m_size;
    vector<int64_t> m_data;
};

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<int64_t> P(N, 0);

    int K = *max_element(A.begin(), A.end());
    vector<bool> have(K + 2, false);
    FenwickTree sum(K + 2), count(K + 2);
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= kLimit && j < A[i]; ++j)
            if (have[j])
                P[i] += A[i] % j;

        for (int div = 1; ; ++div) {
            // maximum is 
            int upper = A[i] / div;
            int lower = max(A[i] / (div + 1), kLimit) + 1;

            if (upper < lower)
                break;
            // for all these the div is `div` 
            // so for x we wanna add A[i] - div * x 
            // -> A[i] * count - div * sum  
            P[i] += A[i] * count.query(lower, upper) - div * sum.query(lower, upper);
        }
        // and those higher , which module == A[i]
        P[i] += A[i] * count.query(A[i] + 1, K);

        // those smaller just get added 
        P[i] += sum.query(A[i] - 1);

        // those bigger depend on size 
        for (int div = 1; div * A[i] <= K; ++div) {
            int lower = A[i] * div;
            int upper = min(A[i] * (div + 1) - 1, K);
            // for x we wanna add x - lower
            // so sum - count * lower
            P[i] += sum.query(lower, upper) - count.query(lower, upper) * lower;
        }
        have[A[i]] = true;
        sum.add(A[i], A[i]);
        count.add(A[i], 1);
    }

    for (int i = 1; i < N; ++i)
        P[i] += P[i - 1];
    for (auto &x : P)
        cout << x << " ";
    cout << "\n";
}