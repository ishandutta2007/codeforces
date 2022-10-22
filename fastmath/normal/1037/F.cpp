#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, k, len;
int a[MAXN];

void read() {
    cin >> n >> k;
    len = k - 1;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int l[MAXN], r[MAXN];

void precalc() {
    for (int i = 0; i < n; ++i) {
        l[i] = -1;
        r[i] = n;
    }
    vector <int> st;
    for (int i = 0; i < n; ++i) {
        while (st.size() && a[st.back()] < a[i]) {
            r[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (st.size() && a[st.back()] <= a[i]) {
            l[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
}

int get(int a, int b) {
    int ta = (a + 1) / len;
    a = (a + 1) % len;
    int tb = (b + 1) / len;
    b = (b + 1) % len;

    int ans = 0;
    ans += ta * tb * len;
    ans += a * tb;
    ans += b * ta;

    ans += (a && b);

    int tl = max(1ll, len - b + 1);
    int tr = a - 1;

    ans += max(0ll, tr - tl + 1);

    ans %= MOD;
    return ans;
}

int ans = 0;
void solve() {
    precalc();
    for (int i = 0; i < n; ++i) {
        int llen = i - l[i] - 1;
        int rlen = r[i] - 1 - i;
        int f = get(llen, rlen) - 1;
        ans += a[i] * f;
        ans = (ans % MOD + MOD) % MOD; 
    }
}

void print() {
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}