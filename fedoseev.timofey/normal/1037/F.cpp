#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += md;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int len(int l, int r, int k) {
    l %= k;
    r %= k;
    if (l <= r) {
        return (r - l + 1) % k;
    } else {
        return (k - (l - r - 1)) % k;
    }
}

int len(int l1, int r1, int l2, int r2, int k) {
    l1 %= k;
    r1 %= k;
    l2 %= k;
    r2 %= k;
    vector <pair <int, int>> ev;
    if (l1 <= r1) {
        ev.emplace_back(l1, -1);
        ev.emplace_back(r1, 1);
    } else {
        ev.emplace_back(l1, -1);
        ev.emplace_back(k - 1, 1);
        ev.emplace_back(0, -1);
        ev.emplace_back(r1, 1);
    }
    if (l2 <= r2) {
        ev.emplace_back(l2, -1);
        ev.emplace_back(r2, 1);
    } else {
        ev.emplace_back(l2, -1);
        ev.emplace_back(k - 1, 1);
        ev.emplace_back(0, -1);
        ev.emplace_back(r2, 1);
    }
    sort(ev.begin(), ev.end());
    int res = 0;
    int last = -1;
    int bal = 0;
    for (auto p : ev) {
        if (p.second == -1) {
            ++bal;
            if (bal == 2) {
                last = p.first;
            }
        } else {
            --bal;
            if (bal == 1) {
                res += p.first - last + 1;
            }
        }
    }
    return res;
}

int get(int l, int r, int k) {
    return (r - l + 1) / k;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <pair <int, int>> st;
    vector <int> L(n, -1), R(n, n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.back().first < a[i]) st.pop_back();
        if (!st.empty()) L[i] = st.back().second;
        st.push_back({a[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.back().first <= a[i]) st.pop_back();
        if (!st.empty()) R[i] = st.back().second;
        st.push_back({a[i], i});
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = L[i] + 1;
        int r = R[i] - 1;
        int cnt = 0;
        add(cnt, mul(mul(get(l, i, k - 1), get(i, r, k - 1)), k - 1));
        add(cnt, mul(get(l, i, k - 1), len(i, r, k - 1)));
        add(cnt, mul(len(l, i, k - 1), get(i, r, k - 1)));
        if (len(l, i, k - 1) && len(i, r, k - 1)) add(cnt, len(l, i, i, r, k - 1));
        add(ans, mul(cnt, a[i]));
    }
    for (int i = 0; i < n; ++i) sub(ans, a[i]);
    cout << ans << '\n';
}