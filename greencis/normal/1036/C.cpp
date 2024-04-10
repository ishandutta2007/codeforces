#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int p[18];

int main() {
    ios_base::sync_with_stdio(false);

    vector<ll> v;
    for (int x = 0; x <= 9; ++x) {
        for (int y = x; y <= 9; ++y) {
            for (int z = y; z <= 9; ++z) {
                memset(p, 0, sizeof p);
                p[15] = x;
                p[16] = y;
                p[17] = z;
                do {
                    ll cur = 0;
                    for (int i = 0; i < 18; ++i)
                        cur = cur * 10 + p[i];
                    v.push_back(cur);
                } while (next_permutation(p, p + 18));
            }
        }
    }
    v.push_back(1e18);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());

    int q;
    cin >> q;
    while (q--) {
        ll L, R;
        cin >> L >> R;
        cout << upper_bound(all(v), R) - lower_bound(all(v), L) << "\n";
    }
}