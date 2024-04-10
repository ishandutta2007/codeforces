#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<pair<int, int>> h;
vector<pair<int, array<int, 5>>> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, b, q; cin >> n >> b >> q;
    int x = 0, y = 0;
    h.resize(q);
    for (int i = 0; i < q; i++)
        cin >> h[i].first >> h[i].second;
    h.pb({b, n});
    sort(all(h));
    debug(h);
    for (auto& [u, c] : h) {
        array<int, 5> a;
        for (int j = 0; j < 5; j++)
            a[j] = ((u+j)/5)-((x+j)/5);
        v.pb({c-y, a});
        x = u, y = c;
    }
    debug(v);
    bool out = 1;
    for (int k = 0; k < 32; k++) {
        int r = 0;
        for (auto& [c, a] : v) {
            int s = 0;
            for (int i = 0; i < 5; i++)
                if (k&(1<<i)) s += a[i];
            r += min(c, s);
        }
        out = out && r >= n/5*__builtin_popcount(k);
    }
    cout << (out ? "fair" : "unfair") << "\n";
}