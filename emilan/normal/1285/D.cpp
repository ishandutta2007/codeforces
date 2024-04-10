#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      (a).begin(), (a).end()
#define RALL(a)     (a).rbegin(), (a).rend()

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

struct BinTrie {
    struct Node {
        int chi[2];
        Node() : chi{-1, -1} {}
        int &operator[](int i) { return chi[i]; }
    };

    deque<Node> a;
    int ptr = 0;

    BinTrie() {
        a.emplace_back();
        ptr++;
    }

    void update(int x) {
        int u = 0;
        for (int k = 29; k >= 0; k--) {
            int i = x >> k & 1;
            if (a[u][i] == -1) {
                a.emplace_back();
                a[u][i] = ptr++;
            }
            u = a[u][i];
        }
    }

    int calc(int u = 0, int k = 29) {
        if (a[u][0] == -1 && a[u][1] == -1) return 0;
        else if (a[u][0] == -1) return calc(a[u][1], k - 1);
        else if (a[u][1] == -1) return calc(a[u][0], k - 1);
        else return 1 << k | min(calc(a[u][0], k - 1), calc(a[u][1], k - 1));
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    BinTrie trie;
    for (int x : a) trie.update(x);
    cout << trie.calc() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}