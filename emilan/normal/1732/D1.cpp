#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

void solve() {
    set<ll> s = {0};
    map<ll, int> idx;

    int q;
    cin >> q;
    while (q--) {
        char t;
        ll x;
        cin >> t >> x;

        if (t == '+') {
            s.insert(x);
        } else if (t == '-') {
            assert(false);
        } else {
            int i = idx[x];
            while (s.count(i * x)) i++;
            cout << i * x << '\n';
            idx[x] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}