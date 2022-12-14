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

  int n, m; cin >> n >> m;
  vector<string> lines(n);
  set<int> dist;
  for (int i = 0; i < n; i++) {
    cin >> lines[i];
    dist.insert(lines[i].find('S') - lines[i].find('G'));
  }
  
  if (*dist.begin() < 0)
    cout << -1;
  else
    cout << sz(dist);

  return 0;
}