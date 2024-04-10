#include <iostream>
#include <vector>

using namespace std;

static const int kMaxN = 100'000;
static const int kInfinite = 1'000'000'001;

class SegmentTree {
  public:
    SegmentTree(int size): m_size(size), m_data(size * 2) {}

    void update_max(int from, int to, int value) {
        update_max(0, 0, m_size, from, to, value);
    }

    void update_min(int from, int to, int value) {
        update_min(0, 0, m_size, from, to, value);
    }

    int64_t query(int from, int to) {
        return query(0, 0, m_size, from, to);
    }

  private:
    struct Node {
        int min1 = -kInfinite, min2 = 0;
        int max1 = kInfinite, max2 = 0;

        int64_t total = 0;
        int max_matched = 0, min_matched = 0;
        bool full_positive = false;
        bool full_negative = false;

        int lazy_max = -kInfinite;
        int lazy_min = kInfinite;
    };

    void propagate(int node, int begin, int end) {
        int mid = (begin + end) / 2;
        update_max(node + 1, begin, mid, begin, mid, m_data[node].lazy_max);
        update_min(node + 1, begin, mid, begin, mid, m_data[node].lazy_min);
        update_max(node + 2 * (mid - begin), mid, end, mid, end, m_data[node].lazy_max);
        update_min(node + 2 * (mid - begin), mid, end, mid, end, m_data[node].lazy_min);
    }

    void compute(int node, int begin, int end) {
        int mid = (begin + end) / 2;
        auto &now = m_data[node];
        auto &left = m_data[node + 1];
        auto &right = m_data[node + 2 * (mid - begin)];

        now.min1 = min(left.min1, right.min1);
        now.min2 = 0;
        for (auto &x : {left.min1, left.min2, right.min1, right.min2})
            if (x != now.min1 && x < now.min2)
                now.min2 = x;

        now.max1 = max(left.max1, right.max1);
        now.max2 = 0;
        for (auto &x : {left.max1, left.max2, right.max1, right.max2})
            if (x != now.max1 && x > now.max2)
                now.max2 = x;

        now.total = left.total + right.total;

        now.min_matched = 0;
        if (left.min1 == now.min1)
            now.min_matched += left.min_matched;
        if (right.min1 == now.min1)
            now.min_matched += right.min_matched;

        now.max_matched = 0;
        if (left.max1 == now.max1)
            now.max_matched += left.max_matched;
        if (right.max1 == now.max1)
            now.max_matched += right.max_matched;

        now.full_negative = (left.full_negative && right.full_negative);
        now.full_positive = (left.full_positive && right.full_positive);

        now.lazy_max = -kInfinite;
        now.lazy_min = kInfinite;
    }

    void update_max(int node, int begin, int end, int from, int to, int value) {
        if (to <= begin || end <= from || value <= m_data[node].min1)
            return;
        if (end - begin == 1) {
            m_data[node].full_negative = true;
            m_data[node].min1 = value;
            m_data[node].max_matched = 1;

            if (m_data[node].full_positive)
                m_data[node].total = m_data[node].max1 - m_data[node].min1;
            return;
        }

        if (from <= begin && end <= to && value < m_data[node].min2 && m_data[node].full_negative) {
            m_data[node].lazy_max = value;
            m_data[node].total -= 1LL * (value - m_data[node].min1) * m_data[node].min_matched;
            m_data[node].min1 = value;
            return;
        }

        propagate(node, begin, end);
        int mid = (begin + end) / 2;

        update_max(node + 1, begin, mid, from, to, value);
        update_max(node + 2 * (mid - begin), mid, end, from, to, value);
        compute(node, begin, end);
    }

    void update_min(int node, int begin, int end, int from, int to, int value) {
        if (to <= begin || end <= from || value >= m_data[node].max1)
            return;
        if (end - begin == 1) {
            m_data[node].full_positive = true;
            m_data[node].max1 = value;
            m_data[node].min_matched = 1;

            if (m_data[node].full_negative)
                m_data[node].total = m_data[node].max1 - m_data[node].min1;
            return;
        }

        if (from <= begin && end <= to && value > m_data[node].max2 && m_data[node].full_positive) {
            m_data[node].lazy_min = value;
            m_data[node].total -= 1LL * (m_data[node].max1 - value) * m_data[node].max_matched;
            m_data[node].max1 = value;
            return;
        }

        propagate(node, begin, end);
        int mid = (begin + end) / 2;
        update_min(node + 1, begin, mid, from, to, value);
        update_min(node + 2 * (mid - begin), mid, end, from, to, value);
        compute(node, begin, end);
    }

    int64_t query(int node, int begin, int end, int from, int to) {
        if (end <= from || to <= begin)
            return 0;
        if (from <= begin && end <= to)
            return m_data[node].total;
        propagate(node, begin, end);
        int mid = (begin + end) / 2;
        return query(node + 1, begin, mid, from, to) + query(node + 2 * (mid - begin), mid, end, from, to);
    }

    int m_size;
    vector<Node> m_data;
};

int main() {
    ios::sync_with_stdio(false);

    SegmentTree S(kMaxN);
    int Q; cin >> Q;

    while (Q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, k; cin >> l >> r >> k;
            if (k < 0)
                S.update_max(l, r, k);
            else 
                S.update_min(l, r, k);
        } else {
            int l, r; cin >> l >> r;
            cout << S.query(l, r) << "\n";
        }
    }
}