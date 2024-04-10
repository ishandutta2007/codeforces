#include <iostream>
#include <pthread.h>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

static const int kInfinite = numeric_limits<int>::max() / 2;

struct Function { 
    int a, b;

    int operator()(int x) const {
        return a * x + b;
    }
};

class KineticTournament {
  public:
    KineticTournament(int size): m_size(size), m_time(-1), m_data(size * 4, Node{Function{0, kInfinite}, kInfinite}) {}

    void update(int position, Function f) {
        update(1, 0, m_size, position, f);
    }

    void heaten(int new_time) {
        m_time = new_time;
        recompute(1, 0, m_size);
    }

    int query() const {
        return query(0, m_size);
    }

    int query(int from, int to) const {
        return query(1, 0, m_size, from, to);
    }

  private:
    struct Node {
        Function f;
        int next_change;
    };

    int intersect(Function f1, Function f2) {
        if (f2.a >= f1.a)
            return kInfinite;
        // f2.a * X + f2.b == f1.a * X + f1.b 
        // (f2.a - f1.a) * X = f1.b - f2.b 
        // X = (f1.b - f2.b) / (f2.a - f1.a)
        int X = (f2.b - f1.b + f1.a - f2.a - 1) / (f1.a - f2.a);
         if (X <= m_time)
             return kInfinite;
         return X;
    }

    void recompute(int node, int begin, int end) {
        if (m_data[node].next_change > m_time)
            return;

        int mid = (begin + end) / 2;
        recompute(node * 2, begin, mid);
        recompute(node * 2 + 1, mid, end);

        auto f1 = m_data[node * 2].f;
        auto f2 = m_data[node * 2 + 1].f;
        if (f1(m_time) > f2(m_time))
            swap(f1, f2);
        if (f1(m_time) == f2(m_time) && f1.a > f2.a)
            swap(f1, f2);
        m_data[node].f = f1;
        m_data[node].next_change = min({m_data[node * 2].next_change, m_data[node * 2 + 1].next_change, intersect(f1, f2)});
    }

    void update(int node, int begin, int end, int position, Function f) {
        if (end - begin == 1) {
            m_data[node] = Node{f, kInfinite};
            return;
        }

        int mid = (begin + end) / 2;
        if (position < mid)
            update(node * 2, begin, mid, position, f);
        else 
            update(node * 2 + 1, mid, end, position, f);
        m_data[node].next_change = -1;
        recompute(node, begin, end);
    }

    int query(int node, int begin, int end, int from, int to) const {
        if (from <= begin && end <= to)
            return m_data[node].f(m_time);

        int mid = (begin + end) / 2;
        int answer = kInfinite;
        if (from < mid)
            answer = min(answer, query(node * 2, begin, mid, from, to));
        if (mid < to)
            answer = min(answer, query(node * 2 + 1, mid, end, from, to));
        return answer;
    }
    int m_size;
    int m_time;
    vector<Node> m_data;
};

int main() {
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    A[0] = kInfinite;

    vector<int> values(A.begin() + 1, A.end());
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    vector<int> dp(N + 1, kInfinite), next(N + 1, kInfinite);
    dp[0] = 0;

    vector<int> prev_higher(N + 1, 0);
    vector<int> stack{0};
    for (int i = 1; i <= N; ++i) {
        while (A[stack.back()] <= A[i])
            stack.pop_back();
        prev_higher[i] = stack.back();
        stack.push_back(i);
    }

    vector<int> by_values(N);
    for (int i = 0; i < N; ++i)
        by_values[i] = i + 1;
    sort(by_values.begin(), by_values.end(), [&](int x, int y) {
        return A[x] < A[y];
    });

    vector<int> best_to(N + 1);
    for (int k = 1; k <= K; ++k) {
        fill(next.begin(), next.end(), kInfinite);
        KineticTournament T(N);
        for (int i = 0; i < N; ++i)
            T.update(i, Function{-i, dp[i]});

        for (auto &pos : by_values) {
            if (pos < k)
                continue;
            T.heaten(A[pos]);
            best_to[pos] = T.query(max(prev_higher[pos], k - 1), pos);
        }

        KineticTournament by_value(values.size());
        stack.clear();
        stack.push_back(0);
        for (int i = k; i <= N; ++i) {
            while (A[stack.back()] <= A[i]) {
                auto value_pos = lower_bound(values.begin(), values.end(), A[stack.back()]) - values.begin();
                by_value.update(value_pos, Function{0, kInfinite});
                stack.pop_back();
            }
            stack.push_back(i);
            auto value_pos = lower_bound(values.begin(), values.end(), A[i]) - values.begin();
            by_value.update(value_pos, Function{A[i], best_to[i]});
            by_value.heaten(i);
            next[i] = by_value.query();
        }

        swap(dp, next);
    }

    cout << dp.back() << "\n";
}