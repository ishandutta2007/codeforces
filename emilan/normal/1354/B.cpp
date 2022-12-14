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
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  dotc() {
    string s;
    cin >> s;
    
    int l = 3, r = sz(s) + 1;
    while (l < r) {
      int mi = (l + r) / 2;
      if (mi == sz(s) + 1) {
        l = mi;
        break;
      }
      vi freq(3);
      rep(i, mi) freq[s[i] - '1']++;
      bool ok = false;
      if (freq[0] && freq[1] && freq[2]) ok = true;
      for (int i = mi; i < sz(s) && !ok; i++) {
        freq[s[i - mi] - '1']--;
        freq[s[i] - '1']++;
        if (freq[0] && freq[1] && freq[2]) ok = true;
      }

      if (ok) r = mi;
      else l = mi + 1;
    }


    if (r == sz(s) + 1)cout << 0 << '\n';
    else cout << r << '\n';
  }

  return 0;
}