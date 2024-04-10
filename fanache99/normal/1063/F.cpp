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

const int MAXN = 500000;
const int SIGMA = 26;

int dp[MAXN];
int tree[1 + 10 * MAXN];

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

    int compute() {
        dp[0] = 1;
        int before = 0, prev = 0, curr = st[0].next[s[0] - 'a'];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + 1;
            prev = st[prev].next[s[i - 1] - 'a'];
            curr = st[curr].next[s[i] - 'a'];
            if (st[st[prev].link].len >= dp[i] - 1) {
                prev = st[prev].link;
            }
            if (st[st[curr].link].len >= dp[i] - 1) {
                curr = st[curr].link;
            }
            while (true) {
                if (dp[i] == 1) {
                    break;
                }
                if (query(1, 1, sz, st[prev].first, st[prev].last) >= dp[i] - 1 ||
                    query(1, 1, sz, st[curr].first, st[curr].last) >= dp[i] - 1) {
                    break;
                }
                dp[i]--;
                if (st[st[prev].link].len >= dp[i] - 1) {
                    prev = st[prev].link;
                }
                if (st[st[curr].link].len >= dp[i] - 1) {
                    curr = st[curr].link;
                }
                before = st[before].next[s[i - dp[i]] - 'a'];
                update(1, 1, sz, st[before].first, dp[i - dp[i]]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    SA sa(s);
    cout << sa.compute();

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}