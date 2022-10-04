#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool prime(int x) {
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) return false;
    }
    return true;
}

int MA, MB;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

struct num {

  int a, b;

  num() : a(0), b(0) {}
  num( int x ) : a(x), b(x) { }
  num( int a, int b ) : a(a), b(b) { }

  num operator + ( const num &x ) const { return num((a + x.a) % MA, (b + x.b) % MB); }
  num operator - ( const num &x ) const { return num((a + MA - x.a) % MA, (b + MB - x.b) % MB); }
  num operator * ( int x ) const { return num(((ll)a * x) % MA, ((ll)b * x) % MB); }
  num operator * ( const num &x ) const { return num(((ll)a * x.a) % MA, ((ll)b * x.b) % MB); }
  bool operator == ( const num &x ) const { return a == x.a && b == x.b; }

  explicit operator ll () const { return (ll)a * MB + b + 1; } // > 0
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    MA = (int)5e8 + rnd() % (int)5e8;
    while (!prime(MA)) ++MA;
    MB = (int)5e8 + rnd() % (int)5e8;
    while (!prime(MB)) ++MB;
    int n, m;
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    vector <vector <num>> dp1(n, vector <num> (m));
    dp1[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n && a[i + 1][j] != '#') dp1[i + 1][j] = dp1[i + 1][j] + dp1[i][j];
            if (j + 1 < m && a[i][j + 1] != '#') dp1[i][j + 1] = dp1[i][j + 1] + dp1[i][j];
        }
    }
    if (dp1[n - 1][m - 1] == 0) {
        cout << "0\n";
        return 0;
    }
    vector <vector <num>> dp2(n, vector <num> (m));
    dp2[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i > 0 && a[i - 1][j] != '#') dp2[i - 1][j] = dp2[i - 1][j] + dp2[i][j];
            if (j > 0 && a[i][j - 1] != '#') dp2[i][j - 1] = dp2[i][j - 1] + dp2[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == n - 1 && j == m - 1) continue;
            if (dp1[i][j] * dp2[i][j] == dp1[n - 1][m - 1]) {
                cout << "1\n";
                return 0;
            }
        }
    }
    cout << "2\n";
}