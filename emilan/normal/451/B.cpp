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

  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  int sIdx = 0, eIdx = n;
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i + 1]) {
      if (!sIdx)
        sIdx = i;
      else if (eIdx != n) {
        ok = false;
        break;
      }
    } else {
      if (sIdx && eIdx == n) {
        eIdx = i;
      }
    }
  }
  
  if ((eIdx != n && a[sIdx] > a[eIdx + 1]) || (sIdx > 1 && a[sIdx - 1] > a[eIdx]))
    ok = false;

  if (ok) {
    cout << "yes\n";
    if (!sIdx)
      cout << "1 1";
    else
      cout << sIdx << ' ' << eIdx;
  } else
    cout << "no";

  return 0;
}