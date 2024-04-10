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

  string s, t; cin >> s >> t;
  map<char, int> sfreq, tfreq;
  for (char& c : s)
    sfreq[c]++;
  
  for (char& c : t) {
    tfreq[c]++;
  }

  int g = 0, b = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    for (int i = -32; i <= 0; i += 32) {
      int yay = min(sfreq[c + i], tfreq[c + i]);
      sfreq[c + i] -= yay;
      tfreq[c + i] -= yay;
      g += yay;
    }

    b += min(sfreq[c - 32], tfreq[c]);
    b += min(sfreq[c], tfreq[c - 32]);
  }

  cout << g << ' ' << b;

  return 0;
}