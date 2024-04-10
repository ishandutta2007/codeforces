#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Feniwick {
    vector <int> f;
    int n;
    Feniwick(int n_) {
        n = n_;
        f.resize(n);
    }
    void modify(int i, int val) {
        for (; i < n; i |= i + 1) f[i] += val;
    }
    int get(int r) {
        int res = 0;
        for (; r >= 0; r &= r + 1, --r) {
            res += f[r];
        }
        return res;
    }
    int sum(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Feniwick f1(n), f2(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) f1.modify(i, 1); 
        else f2.modify(i, 1);
    }
    vector <pair <int, int>> ans;
    for (int s = 1; s <= n; ++s) {
        int cnt1 = 0, cnt2 = 0;
        bool bad = false;

        int uk = 0;
        while (uk < n) {
            int l = uk - 1, r = n;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (f1.sum(uk, m) >= s || f2.sum(uk, m) >= s) r = m;
                else l = m;
            }
            if (r == n) {
                bad = true;
                break;
            }
            if (f1.sum(uk, r) == s) {
                ++cnt1;
                if (r == n - 1 && a.back() == 2) bad = true;
            } else {
                ++cnt2;
                if (r == n - 1 && a.back() == 1) bad = true;
            }
            uk = r + 1;
        }
        if (bad) continue;
        if (a.back() == 1 && cnt1 > cnt2) ans.push_back({cnt1, s});
        if (a.back() == 2 && cnt2 > cnt1) ans.push_back({cnt2, s});
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
}