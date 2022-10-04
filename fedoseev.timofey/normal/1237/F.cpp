#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3607;
 
const int md = 998244353;
 
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
 
int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
 
int inv(int x) {
    return power(x, md - 2);
}
 
int f[N], rf[N];
 
int C(int n, int k) {
    return mul(f[n], mul(rf[n - k], rf[k]));
}

int dpr[N][N], dpc[N][N];

int cntr[N][N], cntc[N][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
    for (int i = 0; i < N; ++i) rf[i] = inv(f[i]);
    int h, w, n;
    cin >> h >> w >> n;
    vector <int> banr(h), banc(w);
    for (int i = 0; i < n; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1, --r2, --c1, --c2;
        banr[r1] = 1;
        banr[r2] = 1;
        banc[c1] = 1;
        banc[c2] = 1;
    }
    int fr = 0, fc = 0;
    for (int i = 0; i < h; ++i) if (banr[i] == 0) ++fr;
    for (int i = 0; i < w; ++i) if (banc[i] == 0) ++fc;

    dpr[0][0] = 1;
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j <= h; ++j) {
            add(dpr[i][j], dpr[i - 1][j]);
            if (j > 0 && i >= 2 && !banr[i - 1] && !banr[i - 2]) add(dpr[i][j], dpr[i - 2][j - 1]);
        }
    }
    dpc[0][0] = 1;
    for (int i = 1; i <= w; ++i) {
        for (int j = 0; j <= w; ++j) {
            add(dpc[i][j], dpc[i - 1][j]);
            if (j > 0 && i >= 2 && !banc[i - 1] && !banc[i - 2]) add(dpc[i][j], dpc[i - 2][j - 1]);
        }
    }
    for (int i = 0; i <= h / 2; ++i) {
        for (int j = 0; j + 2 * i <= fr; ++j) {
            cntr[i][j] = mul(dpr[h][i], C(fr - 2 * i, j));
        }
    }
    for (int i = 0; i <= w / 2; ++i) {
        for (int j = 0; j + 2 * i <= fc; ++j) {
            cntc[i][j] = mul(dpc[w][i], C(fc - 2 * i, j));
        }
    }
    int ans = 0;
    for (int fir = 0; 2 * fir <= fr; ++fir) {
        for (int sec = 0; 2 * sec <= fc; ++sec) {
            add(ans, mul(mul(cntr[fir][sec], cntc[sec][fir]), mul(f[fir], f[sec])));
        }
    }
    cout << ans << '\n';
}