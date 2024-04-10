#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

struct Seg {
    int x, y, z;
};

void solve() {
    int n;
    cin >> n;
    
    if (n == 1) return void(cout << 0);

    vt<int> a(n);
    for (int &i : a) cin >> i;

    vt<Seg> segs{{0, -1, 0}};
    int zero = 0, odd_cnt = (n + 1) / 2, even_cnt = n / 2;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            if (a[i] & 1) odd_cnt--;
            else even_cnt--;
            segs.push_back({segs.back().y, a[i], zero});
            zero = 0;
        } else zero++;
    }
    segs.push_back({segs.back().y, -1, zero});

    if (sz(segs) == 2) return void(cout << 1);

    int ans = 0;
    vt<int> odd, even;
    for (int i = 2; i < sz(segs) - 1; i++) {
        ans += 2;
        if ((segs[i].x ^ segs[i].y) & 1) ans--;
        else if (segs[i].x & 1) odd.push_back(segs[i].z);
        else even.push_back(segs[i].z);
    }
    sort(all(odd));
    sort(all(even));

    for (int i : odd) {
        if (odd_cnt < i) break;
        odd_cnt -= i;
        ans -= 2;
    }

    for (int i : even) {
        if (even_cnt < i) break;
        even_cnt -= i;
        ans -= 2;
    }

    if (segs[1].y & 1) {
        if (odd_cnt < segs[1].z) ans++;
        else odd_cnt -= segs[1].z;
    } else {
        if (even_cnt < segs[1].z) ans++;
        else even_cnt -= segs[1].z;
    }

    if (segs.back().x & 1) {
        if (odd_cnt < segs.back().z) ans++;
        else odd_cnt -= segs.back().z;
    } else {
        if (even_cnt < segs.back().z) ans++;
        else even_cnt -= segs.back().z;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}