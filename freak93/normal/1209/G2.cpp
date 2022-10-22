#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class SegmentTree {
  public:
    SegmentTree(int size): m_size(size), m_data(size * 4) {}

    void update(int from, int to, int with) {
        if (from == to)
            return;
        update(1, 0, m_size, from, to, with);
    }

    void update_max(int position, int value) {
        update_max(1, 0, m_size, position, value);
    }

    int query() {
        return m_data[1].total;
    }

  private:
    struct Node {
        int add = 0;
        int zeros = 1;
        int max_value = 0;
        int max_left = 0;
        int max_right = 0;
        int total = 0;
    };

    void compute(int node) {
        m_data[node].zeros = m_data[node * 2].zeros + m_data[node * 2 + 1].zeros;
        m_data[node].max_value = max(m_data[node * 2].max_value, m_data[node * 2 + 1].max_value);
        if (m_data[node].add > 0)
            m_data[node].zeros = 0;
        if (m_data[node].zeros == 0) {
            m_data[node].max_left = m_data[node].max_right = m_data[node].max_value;
            m_data[node].total = 0;
            return;
        }

        m_data[node].total = m_data[node * 2].total + m_data[node * 2 + 1].total;
        if (m_data[node * 2].zeros && m_data[node * 2 + 1].zeros) {
            m_data[node].total += max(m_data[node * 2].max_right, m_data[node * 2 + 1].max_left);
        }
        m_data[node].max_left = m_data[node * 2].max_left;
        m_data[node].max_right = m_data[node * 2 + 1].max_right;

        if (m_data[node * 2].zeros == 0)
            m_data[node].max_left = max(m_data[node].max_left, m_data[node * 2 + 1].max_left);
        if (m_data[node * 2 + 1].zeros == 0)
            m_data[node].max_right = max(m_data[node].max_right, m_data[node * 2].max_right);
    }

    void update(int node, int begin, int end, int from, int to, int with) {
        if (from <= begin && end <= to) {
            m_data[node].add += with;
            if (m_data[node].add == 0) {
                if (end - begin == 1) {
                    m_data[node].zeros = 1;
                    m_data[node].max_left = m_data[node].max_right = m_data[node].total = 0;
                } else {
                    compute(node);
                }
            } else {
                m_data[node].zeros = 0;
                m_data[node].max_left = m_data[node].max_right = m_data[node].max_value;
                m_data[node].total = 0;
            }
            return;
        }

        int mid = (begin + end) / 2;
        if (from < mid)
            update(node * 2, begin, mid, from, to, with);
        if (mid < to)
            update(node * 2 + 1, mid, end, from, to, with);

        compute(node);
    }

    void update_max(int node, int begin, int end, int position, int value) {
        if (end - begin == 1) {
            m_data[node].max_value = value;
            if (m_data[node].zeros == 0) {
                m_data[node].max_left = m_data[node].max_right = value;
                m_data[node].total = 0;
            }
            return;
        }

        int mid = (begin + end) / 2;
        if (position < mid)
            update_max(node * 2, begin, mid, position, value);
        else
            update_max(node * 2 + 1, mid, end, position, value);
        compute(node);
    }

    int m_size;
    vector<Node> m_data;
};

int main() {
    ios::sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    map<int, set<int> > positions;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        positions[A[i]].insert(i);
    }

    SegmentTree S(2 * N + 1);
    for (auto& [value, pos] : positions) {
        S.update(2 * (*pos.begin() + 1), 2 * (*pos.rbegin() + 1), 1);
        S.update_max(2 * *pos.begin() + 1, pos.size());
    }
    for (int i = 1; i < 2 * N; i += 2)
        S.update(i, i + 1, 2 * N);

    auto update = [&](int value, int with) {
        auto &pos = positions[value];
        if (pos.empty())
            return;

        S.update_max(2 * *pos.begin() + 1, (with == -1 ? 0 : pos.size()));
        S.update(2 * (*pos.begin() + 1), 2 * (*pos.rbegin() + 1), with);
    };

    auto query = [&]() {
        return N - S.query();
    };

    cout << query() << "\n";
    for (int i = 0; i < Q; ++i) {
        int index, value; cin >> index >> value;
        --index;
        int old_value = A[index];
        A[index] = value;

        update(old_value, -1);
        update(value, -1);
        positions[old_value].erase(index);
        positions[value].insert(index);
        update(old_value, 1);
        update(value, 1);

        cout << query() << "\n";
    }
}