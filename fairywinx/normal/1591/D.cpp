#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

struct f {
    vector<int> a;
    int sum = 0;
    f(int n) {
        a.resize(n + 228);
    }
    int get(int pos) {
        int res = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
            res += a[pos];
        return res;
    }

    void update(int pos, int val) {
        ++sum;
        for (; pos < (int) a.size(); pos = (pos | (pos + 1)))
            a[pos]++;
    }
};


bool solve(vector<int> a) {
    int n = a.size();
    if (n < 3) {
        return is_sorted(all(a));
    }
    bool find = false;
    f b(n);
    long long sum = 0;
    for (int j = 0; j < n; ++j) {
        if (b.get(a[j]) - b.get(a[j] - 1)) {
            return true;
        }
        sum += b.sum - b.get(a[j]);
        b.update(a[j], 1);
    }
    if (find) {
        return true;
    } else if (sum % 2 == 0) {
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << (solve(a) ? "YES\n" : "NO\n");
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}