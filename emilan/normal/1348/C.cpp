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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    sort(all(s));

    map<char, int> freq;
    for (char c : s) freq[c]++;

    if (freq.begin()->se < k) cout << s[k - 1] << '\n';
    else {
      string ret(1, freq.begin()->fi);
      if (freq.begin()->se == k) freq.erase(freq.begin());
      if (sz(freq) == 1) {
        ret.append((n - 1) / k, freq.begin()->fi);
      } else {
        ret.append(s.begin() + k, s.end());
      }
      cout << ret << '\n';
    }
  }

  return 0;
}