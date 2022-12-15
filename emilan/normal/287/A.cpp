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

  vector<string> s(4);
  rep(i, 4)
    cin >> s[i];
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int same = 0;
      for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
          if (s[i][j] == s[i + x][j + y])
            same++;
        }
      }

      if (same != 2) {
        cout << "YES";
        return 0;
      }
    }
  }

  cout << "NO";

  return 0;
}