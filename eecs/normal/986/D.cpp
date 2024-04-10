#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;
typedef unsigned long long ull;
const int maxn = 4194304, P = 998244353;
string n;
int lim, L, r[maxn], w[maxn];
poly a, b, c;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void init(int n) {
    for (lim = 1, L = 0; lim < n; lim <<= 1) L++;
    for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    w[lim >> 1] = 1;
    int t = qp(3, (P - 1) / lim);
    for (int i = (lim >> 1) + 1; i < lim; i++) w[i] = 1LL * w[i - 1] * t % P;
    for (int i = (lim >> 1) - 1; i > 0; i--) w[i] = w[i << 1];
}

void DFT(int *a, int type) {
    static ull c[maxn];
    copy(a, a + lim, c);
    for (int i = 0; i < lim; i++) if (i < r[i]) swap(c[i], c[r[i]]);
    for (int i = 1; i < lim; i <<= 1) {
        for (int j = 0; j < lim; j += i << 1) {
            for (int k = 0; k < i; k++) {
                ull t = c[i + j + k] * w[i + k] % P;
                c[i + j + k] = c[j + k] + P - t, c[j + k] += t;
            }
        }
    }
    if (!~type) {
        reverse(c + 1, c + lim);
        for (int i = 0, t = qp(lim, P - 2); i < lim; i++) c[i] = c[i] % P * t % P;
    }
    for (int i = 0; i < lim; i++) a[i] = c[i] % P;
}

poly operator * (poly A, poly B) {
    int len = A.size() + B.size() - 1;
    init(len), A.resize(lim), B.resize(lim);
    DFT(A.data(), 1), DFT(B.data(), 1);
    for (int i = 0; i < lim; i++) A[i] = 1LL * A[i] * B[i] % P;
    DFT(A.data(), -1), A.resize(len); return A;
}

void fix(poly &A) {
    int g = 0;
    for (int &x : A) {
        x += g;
        g = x / 100, x %= 100;
    }
    while (g) {
        A.push_back(g % 100), g /= 100;
    }
}

void qp(poly &A, poly &B, int k) {
    A = {3}, B = {1};
    for (; k; k >>= 1) {
        if (k & 1) B = A * B, fix(B);
        A = A * A, fix(A);
    }
}

bool comp(poly A, poly B) {
    if (A.size() ^ B.size()) return A.size() > B.size();
    reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
    return A >= B;
}

bool chk(poly A, int x) {
    for (int &v : A) v *= x;
    return fix(A), comp(A, a);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    if (n == "1") cout << "1\n", exit(0);
    reverse(n.begin(), n.end());
    for (int i = 0; i < n.size(); i += 2) {
        int x = n[i] - '0';
        if (i + 1 < n.size()) x += 10 * (n[i + 1] - '0');
        a.push_back(x);
    }
    int t = (n.size() - 1) * log(10) / log(3);
    if (t) t--;
    qp(c, b, t);
    int ans = 3 * t;
    while (!comp(b, a)) {
        for (int x : {2, 3, 4}) {
            if (chk(b, x)) { ans += x; goto nxt; }
        }
        for (int &x : b) x *= 3;
        fix(b), ans += 3;
    }
nxt:
    printf("%d\n", ans);
    return 0;
}