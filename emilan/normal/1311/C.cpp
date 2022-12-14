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

#define dotc()  int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)   (int)x.size()
#define eb      emplace_back
#define pb      push_back
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi      first
#define se      second
#define mod     1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  dotc() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> p(n);
    while (m--) {
      int a; cin >> a;
      p[--a]++;
    }

    int cnt = 1;
    vector<int> le(26);
    for (int i = n - 1; i >= 0; i--) {
      cnt += p[i];
      le[s[i] - 'a'] += cnt;
    }

    for (int i = 0; i < 26; i++)
      cout << le[i] << " \n"[i == 25];
  }

  return 0;
}