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

struct SA {
    struct State {
        int len;
        int link;
        map<char, int> next;
        int cnt;
        long long dp;
        vector<int> invLink;
    };

    const string s;
    const int n;
    vector<State> st;
    int last;
    int sz;
    vector<int> order;

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

        while (p != -1 && st[p].next.count(ch) == 0) {
            st[p].next[ch] = curr;
            p = st[p].link;
        }
        if (p == -1) {
            st[curr].link = 0;
        } else {
            int q = st[p].next[ch];
            if (st[q].len == st[p].len + 1) {
                st[curr].link = q;
            } else {
                int clone = sz++;
                st[clone] = st[q];
                st[clone].len = st[p].len + 1;
                st[q].link = st[curr].link = clone;
                while (p != -1 && st[p].next[ch] == q) {
                    st[p].next[ch] = clone;
                    p = st[p].link;
                }
            }
        }

        last = curr;
    }

    SA(const std::string &s) : s(s), n(s.size()) {
        init(n);
        for (auto &ch : s) {
            append(ch);
        }
        for (int i = 1; i < sz; i++) {
            st[st[i].link].invLink.push_back(i);
        }

        vector<bool> seen(sz);
        function<void(int)> get_order = [&](int node) {
            if (seen[node]) {
                return;
            }
            seen[node] = true;
            for (auto [ch, j] : st[node].next) {
                get_order(j);
            }
            order.push_back(node);
        };
        get_order(0);
    }

    void precompute() {
        int i = 0;
        for (auto ch : s) {
            i = st[i].next[ch];
            st[i].cnt = 1;
        }

        function<void(int)> DFS = [&](int node) {
            for (auto son : st[node].invLink) {
                DFS(son);
                st[node].cnt += st[son].cnt;
            }
        };
        DFS(0);
        st[0].cnt = 0;

        for (auto node : order) {
            st[node].dp = st[node].cnt;
            for (auto [ch, other] : st[node].next) {
                st[node].dp += st[other].dp;
            }
        }

        assert(st[0].dp == 1LL * n * (n + 1) / 2);
    }

    string kth(long long k) {
        string ans;
        int i = 0;
        while (true) {
            if (st[i].cnt >= k) {
                return ans;
            }
            k -= st[i].cnt;
            for (auto [ch, j] : st[i].next) {
                if (k > st[j].dp) {
                    k -= st[j].dp;
                } else {
                    ans.push_back(ch);
                    i = j;
                    break;
                }
            }
        }
    }
};



int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    if (1LL * n * (n + 1) / 2 < k) {
        cout << "No such line.\n";
        return 0;
    }

    SA sa(s);
    sa.precompute();
    cout << sa.kth(k) << "\n";

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}