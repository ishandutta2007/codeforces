#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <utility>

using namespace std;

class FenwickTree {
  public:
    FenwickTree(int size): m_data(size, 0) {}

    void update(int pos, int value) {
        for (++pos; pos <= int(m_data.size()); pos += (pos & -pos))
            m_data[pos - 1] += value;
    }

    int query(int to) const {
        int total = 0;
        for (++to; to; to -= (to & -to))
            total += m_data[to - 1];
        return total;
    }

  private:
    vector<int> m_data;
};

struct Piece {
    int first_half;
    int second_half;
    int index;

    bool operator<(const Piece& other) const {
        if (first_half != other.first_half)
            return first_half < other.first_half;
        return second_half < other.second_half;
    }
};


vector<int> suffix_array(const string &S) {
    int N = S.size();
    vector<int> repr(N);
    for (int i = 0; i < N; ++i)
        repr[i] = S[i] - 'a';
    vector<Piece> pieces(N);

    for (int i = 1; i <= N; i *= 2) {
        for (int j = 0; j < N; ++j)
            pieces[j] = Piece{
                repr[j],
                (j + i < N ? repr[j + i] : -1),
                j,
            };
        sort(pieces.begin(), pieces.end());
        int now = -1;
        for (int j = 0; j < N; ++j) {
            if (j == 0 || pieces[j - 1] < pieces[j])
                ++now;
            repr[pieces[j].index] = now;
        }
    }
    vector<int> order(N);
    for (int i = 0; i < N; ++i)
        order[i] = pieces[i].index;
    return order;
}

vector<int> kasai(const string &S, const vector<int> &sa) {
    int N = S.size(), k = 0;
    vector<int> lcp(N - 1, 0);
    vector<int> rank(N, 0);
    for (int i = 0; i < N; ++i)
        rank[sa[i]] = i;

    for (int i = 0; i < N; ++i, k = max(0, k - 1)) {
        if (rank[i] == N - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < N && j + k < N && S[i + k] == S[j + k])
            ++k;
        lcp[rank[i]] = k;
    }
    return lcp;
}

enum TYPE {
    NEGATIVE = 0,
    INSERT = 1,
    POSITIVE = 2,
};

struct Event {
    TYPE type;
    int where;
    int x = 0, y = 0, z = 0;
};

bool operator<(const Event& A, const Event& B) {
    if (A.where != B.where)
        return A.where < B.where;
    return A.type < B.type;
}

int main() {
    ios::sync_with_stdio(false);
    int N, Q; cin >> N >> Q;

    vector<int> position(N), length(N);
    string S;
    for (int i = 0; i < N; ++i) {
        string temp; cin >> temp;
        position[i] = S.size();
        length[i] = temp.size();
        S += temp;
        S += '#';
    }

    auto sa = suffix_array(S);
    auto lcp = kasai(S, sa);

    int L = S.size();
    vector<int> rank(L, 0);
    for (int i = 0; i < L; ++i)
        rank[sa[i]] = i;

    vector<int> need(L, -1);
    for (int i = 0; i < N; ++i)
        need[rank[position[i]]] = length[i];

    vector<int> stack;
    vector<int> left(L), right(L);
    for (int i = 0; i < L; ++i) {
        left[i] = i;
        if (need[i] != -1 && !stack.empty()) {
            auto it = lower_bound(stack.begin(), stack.end(), need[i], [&](int elem, int need) {
                return lcp[elem] < need;
            });
            if (it != stack.begin()) {
                --it;
                left[i] = *it + 1;
            } else {
                left[i] = 0;
            }
        }
        if (i == L - 1)
            break;
        while (!stack.empty() && lcp[stack.back()] >= lcp[i])
            stack.pop_back();
        stack.push_back(i);
    }

    stack.clear();
    for (int i = L - 1; i >= 0; --i) {
        if (i < L) {
            while (!stack.empty() && lcp[stack.back()] >= lcp[i])
                stack.pop_back();
            stack.push_back(i);
        }

        right[i] = i;
        if (need[i] != -1 && !stack.empty()) {
            auto it = lower_bound(stack.begin(), stack.end(), need[i], [&](int elem, int need) {
                return lcp[elem] < need;
            });
            if (it != stack.begin()) {
                --it;
                right[i] = *it;
            } else {
                right[i] = L - 1;
            }
        }
    }

    vector<Event> events;
    for (int i = 0; i < N; ++i)
        for (int j = position[i]; j < position[i] + length[i]; ++j) {
            events.emplace_back(Event{INSERT, i, rank[j]});
        }

    vector<int> answer(Q, 0);
    for (int q = 0; q < Q; ++q) {
        int l, r, k; cin >> l >> r >> k;

        --l; --r;
        k = rank[position[k - 1]];
        events.emplace_back(Event{NEGATIVE, l,  left[k], right[k], q});
        events.emplace_back(Event{POSITIVE, r, left[k], right[k], q});
    }

    sort(events.begin(), events.end());

    FenwickTree FT(L);
    for (auto &event : events) {
        if (event.type == INSERT) {
            FT.update(event.x, 1);
            continue;
        }

        auto now = FT.query(event.y) - FT.query(event.x - 1);
        if (event.type == NEGATIVE)
            answer[event.z] -= now;
        else 
            answer[event.z] += now;
    }
    for (int i = 0; i < Q; ++i)
        cout << answer[i] << "\n";
}