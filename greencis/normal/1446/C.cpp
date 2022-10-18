#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

struct entry {
    int go[2], cnt;
} e[6206006];

int solve(int v) {
    if (e[v].cnt <= 1) return 0;
    int l = e[v].go[0];
    int r = e[v].go[1];
    if (e[l].cnt == 0) return solve(r);
    if (e[r].cnt == 0) return solve(l);
    return min(solve(l) + e[r].cnt - 1, solve(r) + e[l].cnt - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int trie_sz = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int cur = 1;
        for (int bit = 29; bit >= 0; --bit) {
            ++e[cur].cnt;
            int digit = (x >> bit) & 1;
            int& rf = e[cur].go[digit];
            if (rf == 0)
                rf = ++trie_sz;
            cur = rf;
        }
        ++e[cur].cnt;
    }
    int ans = solve(1);
    cout << ans << endl;
}