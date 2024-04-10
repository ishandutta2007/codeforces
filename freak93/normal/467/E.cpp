#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Choice {
    int x, y, z, t;
};

class SegmentTree {
  public:
    SegmentTree(int size):  m_size(size), m_data(size * 2, {-1, -1, -1}) {}

    void update(int l, int r, tuple<int, int, int> value) {
        l += m_size;
        r += m_size;
        while (l < r) {
            if (l % 2) {
                m_data[l] = max(m_data[l], value);
                ++l;
            }
            if (r % 2) {
                --r;
                m_data[r] = max(m_data[r], value);
            }
            l /= 2;
            r /= 2;
        }
    }

    tuple<int, int, int> query(int pos) {
        auto answer = m_data[pos += m_size];
        for (pos /= 2; pos; pos /= 2)
            answer = max(answer, m_data[pos]);
        return answer;
    }

  private:
    int m_size;
    vector<tuple<int, int, int>> m_data;
};

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<Choice> from(N, {-1, -1, -1, -1});
    vector<int> dp(N, 0);
    map<int, vector<int> > positions;
    SegmentTree ST(N);
    for (int i = 0; i < N; ++i) {
        if (i > 0)
            dp[i] = dp[i - 1];
        auto &now = positions[A[i]];
        now.push_back(i);

        if (now.size() < 2)
            continue;
        int j = now[now.size() - 2];

        int best, x, y;
        tie(best, x, y) = ST.query(j);
        ST.update(j + 1, i, {(j > 0 ? dp[j - 1] : 0), j, i});
        if (best + 1 > dp[i]) {
            dp[i] = best + 1;
            from[i] = {x, j, y, i};
        }
        if (now.size() < 4)
            continue;
        best = 0;
        x = now[now.size() - 4];
        y = now[now.size() - 3];
        int z = now[now.size() - 2];
        if (x != 0)
            best = dp[x - 1];
        if (best + 1 > dp[i]) {
            dp[i] = best + 1;
            from[i] = {x, y, z, i};
        }
    }

    vector<int> answer;
    int i = N - 1;
    while (i >= 0) {
        if (from[i].x == -1) {
            --i;
            continue;
        }

        answer.push_back(from[i].t);
        answer.push_back(from[i].z);
        answer.push_back(from[i].y);
        answer.push_back(from[i].x);
        i = from[i].x - 1;
    }

    cout << answer.size() << "\n";
    reverse(answer.begin(), answer.end());
    for (auto &x : answer)
        cout << A[x] << " ";
    cout << "\n";
}