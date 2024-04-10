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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = n;
    for (int i = 0; i < (k + 1) / 2; i++) {
      map<char, int> freq;
      for (int j = 0; j < n / k; j++) {
        freq[s[j * k + i]]++;
        if (!(k & 1) || i != (k - 1) / 2) {
          freq[s[(j + 1) * k - i - 1]]++;
        }
      }
      int mx = 0;
      for (auto& z : freq) {
        if (z.se > mx) mx = z.se;
      }
      cnt -= mx;
    }

    cout << cnt << '\n';
  }

  return 0;
}