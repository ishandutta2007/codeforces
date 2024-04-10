#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>
#include <functional>

using namespace std;
using namespace std::chrono;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    template<typename T>
    inline InputReader &operator>>(T &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];

    inline void advance() {
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int SIGMA = 26;
const int MAXN = 100000;
const int MAXQ = 200000;

int tree[1 + 10 * MAXN];
vector<tuple<int, int, string>> queries[1 + MAXN];
string answer[1 + MAXQ];

void update(int node, int left, int right, int where, int value) {
    if (left == right) {
        tree[node] = max(tree[node], value);
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle) {
        update(2 * node, left, middle, where, value);
    } else {
        update(2 * node + 1, middle + 1, right, where, value);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return tree[node];
    }
    int middle = (left + right) / 2, ans = 0;
    if (from <= middle) {
        ans = max(ans, query(2 * node, left, middle, from, to));
    }
    if (middle + 1 <= to) {
        ans = max(ans, query(2 * node + 1, middle + 1, right, from, to));
    }
    return ans;
}

struct SA {
    struct State {
        int len;
        int link;
        int next[SIGMA];
        vector<int> invLink;
        int first, last;
    };

    const string s;
    const int n;
    vector<State> st;
    int last;
    int sz;

    void init(int n) {
        st.resize(2 * n + 1);
        st[0].len = 0;
        st[0].link = -1;
        last = 0;
        sz = 1;
    }

    void append(char ch) {
        int curr = sz++;
        st[curr].len = st[last].len + 1;
        int p = last;

        while (p != -1 && st[p].next[ch - 'a'] == 0) {
            st[p].next[ch - 'a'] = curr;
            p = st[p].link;
        }
        if (p == -1) {
            st[curr].link = 0;
        } else {
            int q = st[p].next[ch - 'a'];
            if (st[q].len == st[p].len + 1) {
                st[curr].link = q;
            } else {
                int clone = sz++;
                st[clone] = st[q];
                st[clone].len = st[p].len + 1;
                st[q].link = st[curr].link = clone;
                while (p != -1 && st[p].next[ch - 'a'] == q) {
                    st[p].next[ch - 'a'] = clone;
                    p = st[p].link;
                }
            }
        }

        last = curr;
    }

    int cnt = 0;

    void DFS(int node) {
        st[node].first = ++cnt;
        for (auto son : st[node].invLink) {
            DFS(son);
        }
        st[node].last = cnt;
    }

    SA(const std::string &s) : s(s), n(s.size()) {
        init(n);
        for (auto &ch : s) {
            append(ch);
        }
        for (int i = 1; i < sz; i++) {
            st[st[i].link].invLink.push_back(i);
        }
        DFS(0);
    }

    string match(int l, string &x, int pos, int node) {
        int len = pos + 1;
        auto canExtend = [&](char ch) mutable -> bool {
            if (st[node].next[ch - 'a'] == 0) {
                return false;
            }
            int next = st[node].next[ch - 'a'];
            return query(1, 1, sz, st[next].first, st[next].last) >= l + len - 1;
        };

        if (pos == x.size()) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (canExtend(ch)) {
                    return x + ch;
                }
            }
            return "-1";
        } else {
            if (canExtend(x[pos])) {
                string maybe = match(l, x, pos + 1, st[node].next[x[pos] - 'a']);
                if (maybe != "-1") {
                    return maybe;
                }
            }
            for (char ch = x[pos] + 1; ch <= 'z'; ch++) {
                if (canExtend(ch)) {
                    return x.substr(0, pos) + ch;
                }
            }
            return "-1";
        }
    }

    void solve() {
        int r = 0, curr = 0;
        for (auto ch : s) {
            r++;
            curr = st[curr].next[ch - 'a'];
            update(1, 1, sz, st[curr].first, r);

            for (auto &[l, id, x] : queries[r]) {
                int node = 0;
                answer[id] = match(l, x, 0, 0);
            }
        }
    }
};

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    SA sa(s);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        string x;
        cin >> l >> r >> x;
        queries[r].push_back({l, i, x});
    }
    sa.solve();
    for (int i = 1; i <= q; i++) {
        cout << answer[i] << "\n";
    }
    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}