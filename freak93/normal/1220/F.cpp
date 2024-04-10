#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class SegmentTree {
  public:
    SegmentTree(int size):
        m_size(size),
        m_data(4 * size, 0),
        m_max(4 * size, 0) {}

    void add(int from, int to, int value) {
        if (from == to)
            return;
        add(1, 0, m_size, from, to, value);
    }

    int query(int from, int to) {
        return query(1, 0, m_size, from, to);
    }

  private:
    void add(int node, int begin, int end, int from, int to, int value) {
        if (from <= begin && end <= to) {
            m_data[node] += value;
            m_max[node] += value;
            return;
        }

        int mid = (begin + end) / 2;
        if (from < mid)
            add(node * 2, begin, mid, from, to, value);
        if (mid < to)
            add(node * 2 + 1, mid, end, from, to, value);
        m_max[node] = max(m_max[node * 2], m_max[node * 2 + 1]) + m_data[node];
    }

    int query(int node, int begin, int end, int from, int to) {
        if (from <= begin && end <= to)
            return m_max[node];

        int mid = (begin + end) / 2;
        int answer = 0;
        if (from < mid)
            answer = max(answer, query(node * 2, begin, mid, from, to));
        if (mid < to)
            answer = max(answer, query(node * 2 + 1, mid, end, from, to));
        return answer + m_data[node];
    }

    int m_size;
    vector<int> m_data, m_max;
};

int main() {
    int N; cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    A.resize(2 * N);
    for (int i = 0; i < N; ++i)
        A[i + N] = A[i];

    vector<int> left(2 * N, -1), right(2 * N, -1);
    {
        stack<int> S;

        for (int i = 0; i < 2 * N; ++i) {
            while (!S.empty() && A[S.top()] >= A[i]) {
                if (A[S.top()] > A[i])
                    right[S.top()] = i;
                S.pop();
            }

            if (!S.empty())
                left[i] = S.top();
            S.push(i);
        }
    }

    SegmentTree S(2 * N);

    pair<int, int> answer(N + 2, -1);

    for (int i = 0; i < 2 * N; ++i) {
        if (i >= N) {
            if (right[i - N] == -1)
                right[i - N] = i;
            S.add(i - N, right[i - N], -1);
        }

        S.add(left[i] + 1, i, 1);
        if (left[i] != -1)
            S.add(i, i + 1, S.query(left[i], left[i] + 1) + 1);
        else
            S.add(i, i + 1, 1);
        if (i >= N - 1)
            answer = min(answer, make_pair(S.query(i + 1 - N, i + 1), i + 1 - N));
    }

    cout << answer.first << " " << answer.second << "\n";
}