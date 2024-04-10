#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N = 2007;
using bs = bitset <N>;
 
bs a[N];
 
struct Ans {
    int x1, y1, x2, y2; 
    Ans(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    bool operator <(const Ans &other) const {
        if (x1 != other.x1) return x1 < other.x1;
        if (y1 != other.y1) return y1 < other.y1;
        if (x2 != other.x2) return x2 < other.x2;
        return y2 < other.y2;
    }
};
 
set <Ans> hv;
 
void check(int x1, int x2, bool add) {
    bs &f = a[x1], &s = a[x2];
    if ((s & f) == f) return;
    if ((s & f) == s) return;
    int Y1 = (f & (~s))._Find_first();
    int Y2 = (s & (~f))._Find_first();
    int X1 = x1;
    int X2 = x2;
    if (X1 > X2) swap(X1, X2);
    if (Y1 > Y2) swap(Y1, Y2);
    if (add) hv.insert(Ans(X1, Y1, X2, Y2));
    else hv.erase(Ans(X1, Y1, X2, Y2));
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    set <pair <int, int>> s;
    for (int i = 0; i < n; ++i) {
        s.insert({0, i});
    }
    auto xr = [&] (int id, int l, int r) {
        auto it = s.find({a[id].count(), id});
        if (it != s.begin()) {
            check(it->second, prev(it)->second, 0);
        }
        if (next(it) != s.end()) {
            check(it->second, next(it)->second, 0);
        }
        if (it != s.begin() && next(it) != s.end()) {
            check(prev(it)->second, next(it)->second, 1);
        }
        s.erase({a[id].count(), id});
        a[id] ^= (((~bs() >> l) << l) << (N - r - 1)) >> (N - r - 1);
        s.insert({a[id].count(), id});
        it = s.find({a[id].count(), id});
        if (it != s.begin()) {
            check(it->second, prev(it)->second, 1);
        }
        if (next(it) != s.end()) {
            check(it->second, next(it)->second, 1);
        }
        if (it != s.begin() && next(it) != s.end()) {
            check(prev(it)->second, next(it)->second, 0);
        }
    };  
    for (int i = 0; i < q; ++i) {
        int a, l, r;
        cin >> a >> l >> r;
        --a, --l, --r;
        xr(a, l, r);
        if (!hv.empty()) {
            auto ans = *hv.begin();
            cout << ans.x1 + 1 << ' ' << ans.y1 + 1 << ' ' << ans.x2 + 1 << ' ' << ans.y2 + 1 << '\n';
        } else {
            cout << "-1\n";
        }
    }
}