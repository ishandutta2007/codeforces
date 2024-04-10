#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Problem {
    int a;
    int t;
    int index;

    bool operator<(const Problem& that) const {
        return t < that.t;
    }
};

class FenwickTree {
  public:
    FenwickTree(int size):
        m_size(size),
        m_data(size, 0) {}

    void add(int pos, int value) {
        for (++pos; pos <= m_size; pos += (pos & -pos))
            m_data[pos - 1] += value;
    }

    int sum(int pos) {
        int answer = 0;
        for (++pos; pos > 0; pos -= (pos & -pos))
            answer += m_data[pos - 1];
        return answer;
    }

    int search(int total) {
        int step = 1 << 30;
        int where;
        for (where = 0; step > 0; step /= 2)
            if (where + step - 1 < m_size && m_data[where + step - 1] <= total) {
                total -= m_data[where + step - 1];
                where += step;
            }

        if (total > 0)
            return -1;
        return where - 1;
    }

  private:
    int m_size;
    vector<int> m_data;
};

int main() {
    ios::sync_with_stdio(false);

    int N, T; cin >> N >> T;

    vector<Problem> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i].a >> V[i].t;
        V[i].index = i;
    }

    sort(V.begin(), V.end());

    FenwickTree count(N);
    FenwickTree time(N);
    int best = 0;
    for (int i = 0; i < N; ++i) {
        count.add(i, 1);
        time.add(i, V[i].t);
    }

    vector< vector<int> > to_remove(N + 1);
    for (int i = 0; i < N; ++i)
        to_remove[V[i].a].push_back(i);

    for (int i = 1; i <= N; ++i) {
        int where = count.search(i);
        if (where == -1)
            break;
        int total = time.sum(where);
        if (total > T)
            break;
        best = i;

        for (auto &x : to_remove[i]) {
            count.add(x, -1);
            time.add(x, -V[x].t);
        }
    }

    vector<Problem> pick;
    for (int i = 0; i < N; ++i)
        if (V[i].a >= best)
            pick.push_back(V[i]);

    sort(pick.begin(), pick.end());

    vector<int> answer;
    for (int i = 0; i < best; ++i) {
        answer.push_back(pick[i].index);
    }

    cout << best << "\n";
    cout << answer.size() << "\n";
    for (auto &x : answer)
        cout << x + 1 << " ";
    cout << "\n";
}