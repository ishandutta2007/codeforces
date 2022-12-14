#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n; cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];

  if (s[0][0] == s[0][1]) {
    cout << "NO";
    return 0;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || i == n - j - 1) {
        if (s[i][j] != s[0][0]) {
          cout << "NO";
          return 0;
        }
      } else if (s[i][j] != s[0][1]) {
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";

  return 0;
}