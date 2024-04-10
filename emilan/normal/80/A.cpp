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

bool check(int a) {
  for (int i = 2; i < a; i++) {
    if (a % i == 0)
      return false;
  }
  return true;
}

int main() {
  ioThings();

  int a, b; cin >> a >> b;

  for (int i = a + 1; i < b; i++)
    if (check(i)) {
      cout << "NO";
      return 0;
    }
  
  cout << (check(b) ? "YES" : "NO");

  return 0;
}