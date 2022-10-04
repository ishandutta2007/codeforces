#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += md;
}

int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return power(a, md - 2);
}

int getId(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    return 26 + c - 'A';
}

const int N = 1e5 + 7;
int dp[N];

void add(int x) {
    for (int i = N - 1; i >= x; --i) {
        add(dp[i], dp[i - x]);
    }
}

void del(int x) {
    for (int i = 0; i + x < N; ++i) {
        sub(dp[i + x], dp[i]);
    }
}

int ans[52][52];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    vector <int> cnt(52);
    int n = s.size();
    for (auto c : s) ++cnt[getId(c)];
    vector <int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = mul(fact[i - 1], i);

    int cur = mul(fact[n / 2], fact[n / 2]);
    for (int i = 0; i < 52; ++i) if (cnt[i]) cur = mul(cur, inv(fact[cnt[i]]));
    cur = mul(cur, 2);
    dp[0] = 1;
    for (int i = 0; i < 52; ++i) if (cnt[i]) add(cnt[i]);
    for (int i = 0; i < 52; ++i) {
        if (cnt[i]) {
            del(cnt[i]);
            ans[i][i] = mul(cur, dp[n / 2]);
            add(cnt[i]);
        }
    }
    for (int i = 0; i < 52; ++i) {
        if (!cnt[i]) continue;
        del(cnt[i]);
        for (int j = 0; j < 52; ++j) {
            if (i == j || !cnt[j]) continue;
            del(cnt[j]);
            ans[i][j] = mul(cur, dp[n / 2]);
            add(cnt[j]);
        }
        add(cnt[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int i1 = getId(s[x]);
        int i2 = getId(s[y]);
        cout << ans[i1][i2] << '\n';
    }
}