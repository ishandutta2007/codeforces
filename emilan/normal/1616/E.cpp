#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
const i64 kInf = 1LL << 60;

struct Fenwick {
    int n;
    vector<int> a;

    Fenwick(int p_n) : n(p_n), a(n + 1, 1) {
        a[0] = a[1] = 0;
        for (int i = 1; i <= n; i++) {
            if (int j = i + (i & -i); j <= n) a[j] += a[i];
        }
    }

    int query(int i) {
        int res = 0;
        for (i++; i > 0; i -= i & -i) res += a[i];
        return res;
    }

    void update(int i, int d) {
        for (i++; i <= n; i += i & -i) a[i] += d;
    }
};

i64 solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        if (sorted_s >= t) return -1;
    }

    array<stack<int>, 128> pos = {};
    for (int i = n - 1; i >= 0; i--) {
        pos[s[i]].push(i);
    }

    i64 ans = kInf;
    i64 cur = 0;
    Fenwick ft(n);
    for (int i = 0; i < n; i++) {
        int j = n;
        for (char c = 'a'; c < t[i]; c++) if (!pos[c].empty()) {
            j = min(j, pos[c].top());
        }
        if (j < n) ans = min(ans, cur + ft.query(j));

        if (pos[t[i]].empty()) break;
        cur += ft.query(pos[t[i]].top());
        ft.update(pos[t[i]].top(), -1);
        pos[t[i]].pop();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}