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
    int next0, next1, mn;
    node() {
        next0 = next1 = -1;
        mn = 1e9;
    }
};

const int N = 1e5 + 7;

vector <node> trie[N];
vector <int> dv[N];

const int k = 20;

void add(string &s, int u, int uk) {
    int cur = 0;
    for (int i = 0; i < s.size(); ++i) {
        trie[uk][cur].mn = min(trie[uk][cur].mn, u);
        if (s[i] == '0') {
            if (trie[uk][cur].next0 == -1) {
                trie[uk][cur].next0 = trie[uk].size();
                trie[uk].push_back(node());
            }
            cur = trie[uk][cur].next0;
        }
        else {
            if (trie[uk][cur].next1 == -1) {
                trie[uk][cur].next1 = trie[uk].size();
                trie[uk].push_back(node());
            }
            cur = trie[uk][cur].next1;
        }
    }
    trie[uk][cur].mn = min(trie[uk][cur].mn, u);
}

string convert(int x) {
    string res;
    for (int i = 0; i < k; ++i) {
        if (x & (1 << i)) {
            res += '1';
        }
        else {
            res += '0';
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void init() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            dv[j].push_back(i);
        }
    }
    for (int i = 0; i < N; ++i) {
        trie[i].resize(1);
    }
}

int dfs(string &s, int uk, int sum, int cur, int i, int num) {
    if (i == k) {
        return num;
    }
    if (trie[uk][cur].mn > sum) return -1;
    if (s[i] == '1') {
        int nxt = trie[uk][cur].next0;
        if (nxt != -1 && trie[uk][nxt].mn <= sum) {
            return dfs(s, uk, sum, nxt, i + 1, num);
        }
        nxt = trie[uk][cur].next1;
        num += (1 << (k - i - 1));
        return dfs(s, uk, sum, nxt, i + 1, num);
    }
    else {
        int nxt = trie[uk][cur].next1;
        if (nxt != -1 && trie[uk][nxt].mn <= sum) {
            num += (1 << (k - i - 1));
            return dfs(s, uk, sum, nxt, i + 1, num);
        }
        nxt = trie[uk][cur].next0;
        return dfs(s, uk, sum, nxt, i + 1, num);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    int q;
    cin >> q;
    set <int> have;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int u;
            cin >> u;
            if (have.count(u)) continue;
            vector <int> &cur = dv[u];
            string s = convert(u);
            for (auto d : cur) {
                add(s, u, d);
            }
            have.insert(u);
        }
        else {
            int x, k, s;
            cin >> x >> k >> s;
            if (x % k) {
                cout << "-1\n";
                continue;
            }
            if (x >= s) {
                cout << "-1\n";
                continue;
            }
            s -= x;
            string tmp = convert(x);
            cout << dfs(tmp, k, s, 0, 0, 0) << '\n';
        }
    }
}