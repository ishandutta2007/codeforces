#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
    vector<int> len{0};
    vector<int> link{-1};
    vector<map<char, int>> go{{}};
    vector<int> dp{0};
    int sz = 1;
    int last = 0;

    SuffixAutomaton(const string& s) {
        for (char c : s)
            add(c);
        calc();
    }

    void add(char c) {
        len.push_back(len[last] + 1);
        link.push_back(0);
        go.emplace_back();
        dp.push_back(0);
        int cur = sz++;
        int p = last;
        while (p != -1 && !go[p].contains(c)) {
            go[p][c] = cur;
            p = link[p];
        }
        if (p == -1) {
            link[cur] = 0;
        } else {
            int q = go[p][c];
            if (len[p] + 1 == len[q]) {
                link[cur] = q;
            } else {
                int clone = sz++;
                len.push_back(len[p] + 1);
                go.push_back(go[q]);
                link.push_back(link[q]);
                dp.push_back(0);
                while (p != -1 && go[p][c] == q) {
                    go[p][c] = clone;
                    p = link[p];
                }
                link[q] = link[cur] = clone;
            }
        }
        last = cur;
        ++dp[last];
    }

    void calc() {
        vector<int> indeg(sz, 0);
        queue<int> q;
        for (int i = 0; i < sz; ++i) {
            if (link[i] != -1)
                ++indeg[link[i]];
            q.push(i);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (indeg[v] > 0) continue;
            int to = link[v];
            if (to != -1) {
                dp[to] += dp[v];
                --indeg[to];
                q.push(to);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    SuffixAutomaton sa(s), ta(t);

    int mxlen = 1e9;

    function<void(int, int, int)> dfs = [&](int sv, int tv, int curlen) {
        //cerr << "HERE " << sv << " " << tv << " " << sa.dp[sv] << " " << ta.dp[tv] << " " << sa.len[sv] << endl;
        if (curlen != 0 && sa.dp[sv] == 1 && ta.dp[tv] == 1)
            mxlen = min(mxlen, curlen);
        for (auto [sc, sto] : sa.go[sv]) {
            auto it = ta.go[tv].find(sc);
            if (it != ta.go[tv].end()) {
                //cerr << "GO BY " << sc << " " << sa.len[sv] << endl;
                int tto = it->second;
                dfs(sto, tto, curlen + 1);
            }
        }
    };

    dfs(0, 0, 0);
    if (mxlen >= 1e9)
        mxlen = -1;
    cout << mxlen << endl;
}