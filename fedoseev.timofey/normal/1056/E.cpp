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
  bool operator != ( const num &x ) const { return a != x.a || b != x.b; }
  explicit operator ll () const { return (ll)a * MB + b + 1; } // > 0
};

const int P = 239;
const int N = 1e6 + 7;

num deg[N];
num h[N];

void init(string &s) {
    deg[0] = 1;
    h[0] = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        deg[i + 1] = deg[i] * P;
        h[i + 1] = h[i] * P + s[i];
    }
}

num get_hash(int l, int len) {
    return h[l + len] - h[l] * deg[len];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s, t;
    cin >> s >> t;
    init(t);
    int ans = 0;
    int cnt1 = 0, cnt2 = 0;
    int n = s.size();
    int m = t.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ++cnt1;
        else ++cnt2;
    }
    for (int i = 1; i < t.size(); ++i) {
        int sz1 = i;
        if ((ll)i * cnt1 >= t.size()) continue;
        int sz2 = (int)t.size() - (i * cnt1);
        if (sz2 % cnt2) continue;
        sz2 /= cnt2;
        if (sz2 == 0) continue;
        num h1 = 0;
        num h2 = 0;
        bool fnd2 = false;
        bool fnd1 = false;
        int ptr = 0;
        bool fl = true;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '0') {
                if (!fnd1) {
                    fnd1 = true;
                    h1 = get_hash(ptr, sz1);
                }
                if (get_hash(ptr, sz1) != h1) {
                    fl = false;
                    break;
                }
                ptr += sz1;
            }
            else {
                if (!fnd2) {
                    fnd2 = true;
                    h2 = get_hash(ptr, sz2);
                }
                if (get_hash(ptr, sz2) != h2) {
                    fl = false;
                    break;
                }
                ptr += sz2;
            }
        }
        if (fl) assert(ptr == (int)t.size());
        if (fl && h1 != h2) {
            ++ans;
        }
    }
    cout << ans << '\n';
}