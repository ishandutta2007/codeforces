#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int mod = 1e9 + 7;

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


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ll n, m;
    cin >> n >> m;
    if (n < m) {
     	cout << "1\n";
     	exit(0);
    }
    vector <vector <int>> a(1, vector <int> (m));
    a[0][0] = 1;
    for (int i = 1; i < m; ++i) {
     	a[0][i] = a[0][i - 1];
    }
    vector <vector <int>> b(m, vector <int> (m));
    for (int j = 0; j + 1 < m; ++j) {
    	b[j + 1][j] = 1;
    }
    b[0][m - 1] = 1;
    b[m - 1][m - 1] = 1;
    /*for (int i = 0; i <= m; ++i) {
     	for (int j = 0; j <= m; ++j) {
     	 	cout << b[i][j] << ' ';
     	}
     	cout << '\n';
    }  */
    matrix c(a);
    matrix d(b);
    d = powerMatrix(d, n - m + 1);
    c = c.mul(d);
    cout << c.a[0][m - 1] << '\n';
}