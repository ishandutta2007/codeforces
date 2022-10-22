#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int kModulo = 1000 * 1000 * 1000 + 7;

class FenwickTree {
  public:
    FenwickTree(int size): m_data(size, 0) {}

    void update(int pos, int value) {
        for (++pos; pos <= size(); pos += (pos & -pos))
            m_data[pos - 1] = (m_data[pos - 1] + value) % kModulo;
    }

    int query(int pos) const {
        int result = 0;
        for (++pos; pos; pos -= (pos & -pos))
            result = (result + m_data[pos - 1]) % kModulo;
        return result;
    }

    int query(int x, int y) const {
        return (kModulo + query(y) - query(x - 1)) % kModulo;
    }

    int size() const {
        return m_data.size();
    }

  private:
    vector<int> m_data;
};

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> B[i];

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        P[i] = i;
    sort(P.begin(), P.end(), [&](int x, int y) {
        return B[x] < B[y];
    });

    FenwickTree F(3 * N + 3);
    vector<int> first(N), reapply(N);
    int now = 0;
    for (auto &x : P) {
        now = (now + 1) % kModulo;
        first[x] = now;
        reapply[x] = (F.query(A[x], 2 * N) + 1) % kModulo;
        F.update(A[x], reapply[x]);
        now = (now + reapply[x] - 1) % kModulo;
    }

    int T; cin >> T;
    vector<int> S(T);
    vector<bool> need(N, false);
    for (int i = 0; i < T; ++i) {
        cin >> S[i];
        --S[i];
        need[S[i]] = true;
    }

    int answer = 0;
    int older = 0;
    reverse(P.begin(), P.end());

    for (auto &x : P) {
        if (need[x] || A[x] < older) {
            answer = (answer + reapply[x]) % kModulo;
            older = max(older, A[x]);
            continue;
        }
    }

    if (answer < 0)
        answer += kModulo;

    cout << answer << "\n";
}