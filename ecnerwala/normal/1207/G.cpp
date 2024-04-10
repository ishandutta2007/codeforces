#include<bits/stdc++.h>
using namespace std;

template <class F>
struct y_combinator {
    F f; // the lambda will be stored here

    // a forwarding operator():
    template <class... Args> decltype(auto) operator()(Args&&... args) const {
        return f(std::ref(*this), std::forward<Args>(args)...);
    }
};

// helper function that deduces the type of the lambda:
template <class F> y_combinator<std::decay_t<F>> make_y_combinator(F&& f) {
    return {std::forward<F>(f)};
}

const int MAXN = 4.1e5;
int N;
int ind[MAXN];

const int MAXNODE = MAXN;
int NODE = 1;
int ch[MAXNODE][26];

//string trie_path[MAXNODE];

const int MAXM = 4.1e5;
int M;
int ans[MAXM];

const int MAXAH = 4.1e5;
int AH = 1;
int ah_ch[MAXAH][26];
//string ah_path[MAXAH];
int ah_fail[MAXAH];
vector<int> ah_fail_ch[MAXAH];
int ah_st[MAXAH];
int ah_en[MAXAH];

vector<pair<int, int>> queries[MAXNODE];

const int S = 1 << 19;
int seg[2 * S];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t; cin >> t;
        int j;
        if (t == 1) {
            j = 0;
        } else {
            cin >> j;
        }
        char c; cin >> c;
        int node = ind[j];
        if (!ch[node][c-'a']) {
            ch[node][c-'a'] = NODE;
            //trie_path[NODE] = trie_path[node] + c;
            NODE++;
        }
        ind[i] = ch[node][c-'a'];
    }

    cin >> M;
    for (int q = 0; q < M; q++) {
        int i; string t; cin >> i >> t;
        int node = ind[i];
        int cur = 0;
        for (char c : t) {
            if (!ah_ch[cur][c-'a']) {
                ah_ch[cur][c-'a'] = AH;
                //ah_path[AH] = ah_path[cur] + c;
                AH++;
            }
            cur = ah_ch[cur][c-'a'];
        }

        queries[node].emplace_back(cur, q);
    }

    vector<int> ah_queue({0});
    ah_queue.reserve(AH);
    ah_fail[0] = -1;
    for (int z = 0; z < int(ah_queue.size()); z++) {
        int cur = ah_queue[z];
        //if (cur) cerr << "AH " << ah_path[cur] << ' ' << ah_path[ah_fail[cur]] << '\n';
        for (int c = 0; c < 26; c++) {
            int nxt = ah_ch[cur][c];
            int nxt_fail = ah_fail[cur] == -1 ? 0 : ah_ch[ah_fail[cur]][c];
            if (!nxt) {
                ah_ch[cur][c] = nxt_fail;
                continue;
            }
            ah_queue.push_back(nxt);
            ah_fail[nxt] = nxt_fail;
            ah_fail_ch[ah_fail[nxt]].push_back(nxt);
        }
    }

    {
        int incr = 0;
        make_y_combinator([&](auto dfs_preorder, int cur) -> void {
            ah_st[cur] = incr;
            ++incr;
            for (int nxt : ah_fail_ch[cur]) {
                dfs_preorder(nxt);
            }
            ah_en[cur] = incr;
        })(0);
    }

    {
        make_y_combinator([&](auto dfs_trie, int cur, int state) -> void {
            //cerr << "cur " << trie_path[cur] << ' ' << "state " << ah_path[state] << '\n';
            for (int a = S+ah_st[state]; a; a /= 2) {
                seg[a] ++;
            }
            for (auto it : queries[cur]) {
                int v = 0;
                for (int l = S+ah_st[it.first], r = S+ah_en[it.first]; l < r; l /= 2, r /= 2) {
                    if (l & 1) {
                        v += seg[l];
                        l++;
                    }
                    if (r & 1) {
                        --r;
                        v += seg[r];
                    }
                }
                ans[it.second] = v;
            }
            for (int c = 0; c < 26; c++) {
                int nxt = ch[cur][c];
                if (!nxt) continue;
                dfs_trie(nxt, ah_ch[state][c]);
            }
            for (int a = S+ah_st[state]; a; a /= 2) {
                seg[a] --;
            }
        })(0, 0);
    }

    for (int q = 0; q < M; q++) {
        cout << ans[q] << '\n';
    }

    return 0;
}