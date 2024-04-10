#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e6 + 3;

void add(int &a, int b) {
    a += b;
    a %= md;
    a += md;
    a %= md;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
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

int inv[md];

const int K = 11;

vector <int> ans(K);

int get(int x) {
    int res = 0;
    int cur = 1;
    for (int i = 0; i < (int)ans.size(); ++i) {
        add(res, mul(ans[i], cur));
        cur = mul(cur, x);
    }
    return res;
}

int query(int x) {
    cout << "? " << x << endl;
    int r;
    cin >> r;
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 1; i < md; ++i) inv[i] = power(i, md - 2);
    vector <vector <int>> a(K, vector <int> (K + 1));
    for (int i = 0; i < K; ++i) {
        int cur = 1;
        for (int j = 0; j < K; ++j) {
            a[i][j] = cur;
            cur = mul(cur, i);
        }
        a[i][K] = query(i);
    }
    for (int i = 0; i < K; ++i) {
        int who = -1;
        for (int j = i; j < K; ++j) {
            if (a[j][i] && who == -1) {
                who = j;
            }
        }
        if (who == -1) continue;
        swap(a[i], a[who]);
        int d = inv[a[i][i]];
        for (int j = 0; j <= K; ++j) {
            a[i][j] = mul(a[i][j], d);
        }

        for (int j = i + 1; j < K; ++j) {
            int x = a[j][i];
            for (int k = i; k <= K; ++k) {
                add(a[j][k], -mul(x, a[i][k]));
            }
        }
    }
    for (int i = K - 1; i >= 0; --i) {
        int res = 0;
        for (int j = 0; j < K; ++j) {
            add(res, mul(ans[j], a[i][j]));
        }
        ans[i] = a[i][K];
        add(ans[i], -res);
    }
    for (int i = 0; i < md; ++i) {
        if (get(i) == 0) {
            cout << "! " << i << endl;
            return 0;
        }
    }
    cout << "! " << -1 << endl;
}