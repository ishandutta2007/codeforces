#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

const int kA = 1e7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    array<int, kA + 1> freq = {};
    for (int x : a) freq[x]++;

    bitset<kA + 1> is_comp;
    array<int, kA + 1> div = {};
    for (int i = 2; i <= kA; i++) if (!is_comp[i]) {
        for (int j = i; j <= kA; j += i) {
            if (j != i) is_comp[j] = true;
            div[i] += freq[j];
        }
    }

    array<ll, kA + 2> div_pre = {};
    for (int i = 2; i <= kA; i++) {
        div_pre[i + 1] = div_pre[i] + div[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        r = min(r, kA) + 1;
        l = min(l, kA);
        cout << div_pre[r] - div_pre[l] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}