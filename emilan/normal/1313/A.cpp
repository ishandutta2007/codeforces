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

  dotc() {
    int cnt = 0;
    vector<int> a(3); cin >> a[0] >> a[1] >> a[2];
    sort(rall(a));
    if (a[0])
      a[0]--, cnt++;
    if (a[1])
      a[1]--, cnt++;
    if (a[2])
      a[2]--, cnt++;
    
    if (a[0] && a[1])
      a[0]--, a[1]--, cnt++;
    if (a[0] && a[2])
      a[0]--, a[2]--, cnt++;
    if (a[1] && a[2])
      a[1]--, a[2]--, cnt++;
    if (a[0] && a[1] && a[2])
      a[0]--, a[2]--, a[1]--, cnt++;
    
    cout << cnt << '\n';
  }

  return 0;
}