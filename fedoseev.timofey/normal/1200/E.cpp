#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct num {
  static const int MA = 1e9 + 7, MB = 1e9 + 9;

  int a, b;

  num() { }
  num( int x ) : a(x), b(x) { }
  num( int a, int b ) : a(a), b(b) { }

  num operator + ( const num &x ) const { return num((a + x.a) % MA, (b + x.b) % MB); }
  num operator - ( const num &x ) const { return num((a + MA - x.a) % MA, (b + MB - x.b) % MB); }
  num operator * ( int x ) const { return num(((ll)a * x) % MA, ((ll)b * x) % MB); }
  num operator * ( const num &x ) const { return num(((ll)a * x.a) % MA, ((ll)b * x.b) % MB); }
  bool operator == ( const num &x ) const { return a == x.a && b == x.b; }

  explicit operator ll () const { return (ll)a * MB + b + 1; } // > 0
};

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const num P = 239 + (rnd() % (int)1e9);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <num> h(1, 0);
    int ln = 0;
    string ans;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        num H = 0;
        int best = 0;
        num deg = 1;
        for (int x = 1; x <= min((int)s.size(), ln); ++x) {
            deg = deg * P;
            H = H * P + s[x - 1];
            if (H == (h.back() - h[ln - x] * deg)) best = x;
        }
        s = s.substr(best);
        ans += s;
        ln += (int)s.size();
        for (int j = 0; j < (int)s.size(); ++j) {
            h.push_back(h.back() * P + s[j]);
        }
    }
    cout << ans << '\n';
}