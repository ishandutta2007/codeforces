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

  string s; cin >> s;

  int pos = -1;
  vector<int> miss(26);
  for (int i = 0; i < sz(s) - 25; i++) {
    set<char> f;
    for (int j = 0; j < 26; j++) {
      char c = s[i + j];
      if (c != '?') {
        if (f.count(c)) break;
        f.insert(c);
      }

      if (j == 25) {
        pos = i;
        for (char v : f) miss[v - 'A'] = 1;
      }
    }

    if (pos != -1) break;
  }

  if (pos == -1) cout << -1;
  else {
    int j = 0;
    for (int i = 0; i < sz(s); i++) {
      if (s[i] == '?') {
        if (i < pos || i > pos + 25) s[i] = 'A';
        else {
          while (miss[j]) j++;
          s[i] = 'A' + j++;
        }
      }
    }
    cout << s;
  }

  return 0;
}