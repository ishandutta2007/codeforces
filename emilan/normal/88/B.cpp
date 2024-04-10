#include <bits/stdc++.h>
using namespace std;

void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

using   ll        = long long;
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


int main() {
  ioThings();

  int n, m, x; cin >> n >> m >> x;
  vector<string> kb(n);
  for (int i = 0; i < n; i++)
    cin >> kb[i];
  
  int q; cin >> q;
  string s; cin >> s;

  set<char> allKeys;
  bool hasShift = false;
  for (auto& i : kb) {
    for (char& c : i) {
      if (c == 'S')
        hasShift = true;
      else
        allKeys.insert(c);
    }
  }

  set<char> cantCap(allKeys);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (kb[i][j] == 'S')
        for (int ii = 0; ii < n; ii++)
          for (int jj = 0; jj < m; jj++)
            if (hypot(ii - i, jj - j) <= x && cantCap.count(kb[ii][jj]))
              cantCap.erase(kb[ii][jj]);

  int cnt = 0;
  for (char& c : s) {
    if (!allKeys.count(tolower(c))) {
      cnt = -1;
      break;
    }
    if (isupper(c)) {
      if (!hasShift) {
        cnt = -1;
        break;
      } else if (cantCap.count(tolower(c)))
        cnt++;
    }
  }

  cout << cnt;

  return 0;
}