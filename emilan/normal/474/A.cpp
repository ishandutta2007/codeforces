#include <bits/stdc++.h>
using namespace std;

void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
  freopen("io\\err.txt", "w", stderr);
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

  const string kb[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
  char shift; cin >> shift;
  string s; cin >> s;
  for (char& c : s) {
    for (int i = 0; i < 3; i++) {
      int pos = kb[i].find(c);
      if (pos != kb[i].npos) {
        cout << (shift == 'R' ? kb[i][pos - 1] : kb[i][pos + 1]);
        break;
      }
    }
  }


  return 0;
}