#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
  public:
    SegmentTree(int size, int data_size):
        m_size(size),
        m_data_size(data_size),
        m_data((size + 1) * 4),
        m_rooks(size + 1) {
    }

    void insert(int x, int y) {
        m_rooks[x].push_back(y);
    }

    void prepare() {
        prepare(1, 1, m_size);
    }

    bool query(int from, int to, int y1, int y2) {
        return query(1, 1, m_size, from, to, y1, y2);
    }

  private:
    bool query(int node, int begin, int end, int from, int to, int y1, int y2) {
        if (from <= begin && end <= to) {
            auto it = lower_bound(m_data[node].begin(), m_data[node].end(), make_pair(y1, m_data_size + 1));
            if (it == m_data[node].begin())
                return false;
            --it;
            if (it->first <= y1 && it->second >= y2)
                return true;
            return false;
        }

        int mid = (begin + end) / 2;
        if (from <= mid)
            if (query(node * 2, begin, mid, from, to, y1, y2))
                return true;
        if (mid < to)
            if (query(node * 2 + 1, mid + 1, end, from, to, y1, y2))
                return true;
        return false;
    }
    void prepare(int node, int begin, int end) {
        if (begin == end) {
            int last = 0;
            sort(m_rooks[begin].begin(), m_rooks[end].end());
            for (auto &x : m_rooks[begin]) {
                if (x != last + 1)
                    m_data[node].push_back(make_pair(last + 1, x - 1));
                last = x;
            }
            if (last < m_data_size)
                m_data[node].push_back(make_pair(last + 1, m_data_size));
            return;
        }

        int mid = (begin + end) / 2;
        prepare(node * 2, begin, mid);
        prepare(node * 2 + 1, mid + 1, end);
        merge(m_data[node], m_data[node * 2], m_data[node * 2 + 1]);
    }

    void merge(vector< pair<int, int> >& dest, const vector< pair<int, int> > &A, const vector< pair<int, int> > &B) {
        int N = A.size();
        int M = B.size();
        int i = 0, j = 0;
        while (i < N || j < M) {
            if (i == N) {
                dest.push_back(B[j++]);
                continue;
            }
            if (j == M) {
                dest.push_back(A[i++]);
                continue;
            }

            if (A[i] == B[j]) {
                dest.push_back(A[i++]);
                ++j;
                continue;
            }

            if (A[i].first <= B[j].first && A[i].second >= B[j].second) {
                ++j;
                continue;
            }

            if (B[j].first <= A[i].first && B[j].second >= A[i].second) {
                ++i;
                continue;
            }
            if (A[i].first <= B[j].first) {
                dest.push_back(A[i++]);
            } else {
                dest.push_back(B[j++]);
            }
        }
    }

    int m_size, m_data_size;
    vector< vector< pair<int, int> > > m_data;

    vector< vector<int> > m_rooks;
};

int main() {
    ios::sync_with_stdio(false);

    int N, M, K, Q; cin >> N >> M >> K >> Q;

    SegmentTree OX(N, M), OY(M, N);
    for (int i = 0; i < K; ++i) {
        int x, y; cin >> x >> y;
        OX.insert(x, y);
        OY.insert(y, x);
    }
    OX.prepare();
    OY.prepare();

    for (int i = 0; i < Q; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        if (OX.query(x1, x2, y1, y2) && OY.query(y1, y2, x1, x2))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}