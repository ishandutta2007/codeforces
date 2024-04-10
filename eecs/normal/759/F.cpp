#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> info;
const int maxn = 100010, B = 35000, P = 1000000007, P2 = P - 1;
int n, lnk[maxn], nxt[maxn], pw[B + 10], pw2[B + 10];
info h[maxn][2];
string str;

int qp(int k) {
    return 1LL * pw[k % B] * pw2[k / B] % P;
}

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

info operator + (const info &p, const info &q) {
    return {(p[0] + q[0]) % P2, (1LL * p[1] * qp(q[0]) + q[1]) % P};
}

info operator - (const info &p, const info &q) {
    int len = (p[0] - q[0] + P2) % P2;
    return {len, (p[1] - 1LL * q[1] * qp(len) % P + P) % P};
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str, n = str.size();
    for (int i = pw[0] = pw2[0] = 1; i <= B; i++) {
        pw[i] = 10LL * pw[i - 1] % P;
    }
    pw2[1] = pw[B];
    for (int i = 2; i < B; i++) {
        pw2[i] = 1LL * pw2[1] * pw2[i - 1] % P;
    }
    auto geo = [&](int n, int _n, int p) -> int { // 1 + p + p^2 + ... + p^n
        if (p == 1) return (n + 1) % P;
        return 1LL * (qp(p, _n + 1) + P2) * qp(p + P2, P - 2) % P;
    };
    auto sum = [&](int n, int _n, int p) { // p + 2 * p^2 + 3 * p^3 + ... + n * p^n
        if (p == 1) return 1LL * n * (n + 1) / 2 % P;
        int s = 1LL * (n + 1) * qp(p, _n + 1) % P, ip = qp(p - 1, P - 2);
        s = (1LL * s - geo(n + 1, _n + 1, p) + 1 + 2 * P) % P;
        return 1LL * s * ip % P;
    };
    auto calc = [&](string n) {
        info ans{};
        int num = 0, r = 9, _r = 9, pw = 1;
        for (int i = 1; i < n.size(); i++, pw = 10LL * pw % P2) {
            int p = qp(i);
            int v = (r - qp(i - 1) + P) % P, v0 = (_r - pw + P2) % P2;
            int s = (1LL * r * geo(v, v0, p) - sum(v, v0, p) + P) % P;
            ans = ans + info{1LL * i * (v0 + 1) % P2, s};
            r = (10LL * r + 9) % P, _r = (10LL * _r + 9) % P2;
        }
        r = 0, _r = 0;
        for (char ch : n) {
            r = (10LL * r + ch - '0') % P, _r = (10LL * _r + ch - '0') % P2;
        }
        int p = qp(n.size());
        int v = (r - qp(n.size() - 1) + P) % P, v0 = (_r - pw + P2) % P2;
        int s = (1LL * r * geo(v, v0, p) - sum(v, v0, p) + P) % P;
        return ans + info{1LL * n.size() * (v0 + 1) % P2, s};
    };
    vector<int> st;
    nxt[n] = -1;
    for (int i = n - 1; ~i; i--) {
        if (str[i] == '(') lnk[i] = st.back(), st.pop_back();
        if (str[i] == ')') st.push_back(i);
        if (str[i] == '+') nxt[i] = i;
        else nxt[i] = str[i] == '(' ? nxt[lnk[i] + 1] : nxt[i + 1];
    }
    function<info(int, int)> solve = [&](int l, int r) {
        if (~nxt[l] && nxt[l] < r) {
            return solve(l, nxt[l] - 1) + solve(nxt[l] + 1, r);
        }
        int p = l;
        while (p <= r && isdigit(str[p])) p++;
        string v(str.begin() + l, str.begin() + p);
        if (p > r) {
            int s = 0;
            for (char ch : v) s = (10LL * s + ch - '0') % P;
            return info{v.size(), s};
        }
        if (str[p] == '-') {
            int i = v.size() - 1;
            while (v[i] == '0') v[i--] = '9';
            return v[i]--, calc(string(str.begin() + p + 1, str.begin() + r + 1)) - calc(v);
        }
        info pw = solve(p + 1, r - 1), res{};
        for (int i = p - 1; i >= l; i--) {
            for (int j = 1; j <= str[i] - '0'; j++) res = res + pw;
            auto o = pw;
            pw = pw + pw, pw = pw + pw, pw = pw + pw, pw = pw + o + o;
        }
        return res;
    };
    printf("%d\n", solve(0, n - 1)[1]);
    return 0;
}