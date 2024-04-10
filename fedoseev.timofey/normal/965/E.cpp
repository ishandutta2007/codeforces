#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

struct node {
    int term;
    vector <int> next;
    node() {
        term = 0;
        next.resize(26, -1);
    }
};

vector <node> trie;
vector <multiset <int>> s;

int uk = 0;
void add(string &t) {
    int cur = 0;
    for (auto c : t) {
        if (trie[cur].next[c - 'a'] == -1) {
            trie[cur].next[c - 'a'] = ++uk;
            trie.push_back(node());
            s.push_back({});
        }
        cur = trie[cur].next[c - 'a'];
    }
    ++trie[cur].term;
    s[cur].insert((int)t.size());
}

void dfs(int u = 0, int len = 0) {
    for (int i = 0; i < 26; ++i) {
        int v = trie[u].next[i];
        if (v == -1) continue;
        dfs(v, len + 1);
        for (auto x : s[v]) {
            s[u].insert(x);
        }
        s[v].clear();
    }
    if (!trie[u].term) {
        s[u].erase(--s[u].end());
        s[u].insert(len);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    trie.resize(1);
    s.resize(1);
    trie[0].term = 1;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        add(s);
    }
    dfs();
    int ans = 0;
    for (auto x : s[0]) {
        ans += x;
    }
    cout << ans << "\n";
}