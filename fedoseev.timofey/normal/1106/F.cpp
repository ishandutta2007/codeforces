#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int mod = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int sum(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}

int mul(int a, int b) {
    return ((ll)a * b) % mod;
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

struct matrix {
    int n, m;
    vector <vector <int>> a;
    matrix(const vector <vector <int>> &b) {
        a = b;
        n = b.size();
        m = b[0].size();
    }
    matrix (int _n) {
        a.resize(_n, vector <int> (_n));
        n = _n;
        m = _n;
        for (int i = 0; i < n; ++i) {
            a[i][i] = 1;
        }
    }
    matrix mul(const matrix &b) const {
        int k = b.a[0].size();
        vector <vector <int>> res(n, vector <int> (k));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                for (int t = 0; t < m; ++t) {
                    add(res[i][j], ::mul(a[i][t], b.a[t][j]));
                }
            }
        }
        return res;
    }
};

matrix powerMatrix(matrix a, ll b) {
    matrix res((int)a.a.size());
    while (b > 0) {
        if (b & 1) res = res.mul(a);
        a = a.mul(a);
        b >>= 1;
    }
    return res;
}

void exGcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
    }
    else {
        ll x1, y1;
        exGcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
    }
}

int inv(int a) {
    return power(a, mod - 2);
}

int getFir(int md) {
    mod = md;
    vector <int> to_check;
    int ph = md - 1;
    for (int i = 2; i * i <= ph; ++i) {
        if (ph % i == 0) {
            to_check.push_back(i);
            while (ph % i == 0) ph /= i;
        }
    }
    if (ph > 1) to_check.push_back(ph);
    for (int g = 2; g <= mod; ++g) {
        bool bad = false;
        for (auto x : to_check) {
            if (power(g, (md - 1) / x) == 1) {
                bad = true;
                break;
            }
        }
        if (!bad) return g;
    }
    exit(1);
}

int getSec(int a, int b, int md) {
    mod = md;
    int k = sqrt(md) + 1;
    unordered_map <int, int> kekos;
    int t = power(a, k);
    int cur = 1;
    for (int i = 0; i * k <= md; ++i) {
        if (kekos.find(cur) == kekos.end()) {
            kekos[cur] = i * k;
        }
        cur = mul(cur, t);
    }
    int ans = INT_MAX;
    bool ok = false;
    t = inv(a);
    cur = b;
    for (int i = 0; i < k; ++i) {
        if (kekos.count(cur)) {
            ans = min(ans, i + kekos[cur]);
            ok = true;
        }
        cur = mul(cur, t);
    }
    if (!ok) return -1;
    return ans;
}

void solve(int a, int b) {
    int g = getFir(mod);
    int c = getSec(g, b, mod);
    if (c == -1) {
        cout << "-1\n";
        return;
    }
    int phi = mod - 1;
    int gc = gcd(a, phi);
    if (c % gc) {
        cout << "-1\n";
        return;
    }
    int z, l;
    exGcd(a, phi, z, l);
    z *= (c / gc);
    if (z < 0) {
        int ty = phi / gc;
        int hy = (abs(z) + ty - 1) / ty;
        z += hy * ty;
    }
    int ans = power(g, z);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int k;
    cin >> k;
    vector <int> b(k);
    for (int i = 0; i < k; ++i) cin >> b[i];
    int n, m;
    cin >> n >> m;
    matrix a(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            a.a[i][j] = 0;
        }
    }
    for (int i = 0; i < k; ++i) {
        a.a[i][k - 1] = b[k - i - 1];
    }
    for (int i = 0; i + 1 < k; ++i) {
        a.a[i + 1][i] = 1;
    }
    --mod;
    a = powerMatrix(a, n - k);
    vector <vector <int>> cur(1, vector <int> (k));
    for (int i = 0; i < k; ++i) {
        if (i + 1 < k) cur[0][i] = 0;
        if (i == k - 1) {
            cur[0][i] = 1;
        }
    }
    matrix kek(cur);
    kek = kek.mul(a);
    ++mod;
    solve(kek.a[0][k - 1], m);
}