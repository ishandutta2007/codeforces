#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  dotc() {
    int n; cin >> n;
    string a, b;
    bool flag = false;
    while (n--) {
      char c; cin >> c;
      if (c == '0') {
        a += '0';
        b += '0';
      } else if (c == '1') {
        if (flag) {
          a += '0';
          b += '1';
        } else {
          flag = true;
          a += '1';
          b += '0';
        }
      } else if (c == '2') {
        if (flag) {
          a += '0';
          b += '2';
        } else {
          a += '1';
          b += '1';
        }
      }
    }
    cout << a << '\n' << b << '\n';
  }

  return 0;
}