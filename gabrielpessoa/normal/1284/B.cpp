#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
 
const int ms = 2e6+5;
const int inf = 1e18;
const int mod = 998244353;

int lo[ms], hi[ms];
bool hasAscent[ms];
vector<int> allHis;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int amountWithAscent = 0;
  for(int i =0 ; i < n; i++) {
    int l;
    cin >> l;
    cin >> lo[i];
    hi[i] = lo[i];
    for(int j = 1; j < l; j++) {
      int x;
      cin >> x;
      if(x > lo[i]) hasAscent[i] = 1;
      lo[i] = min(lo[i], x);
      hi[i] = max(hi[i], x);
    }
    if (hasAscent[i]) amountWithAscent++;
    else allHis.push_back(hi[i]);
  }
  sort(allHis.begin(), allHis.end());
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(hasAscent[i]) ans += n;
    else {
      ans += amountWithAscent;
      int k = allHis.end() - upper_bound(allHis.begin(), allHis.end(), lo[i]);
      ans += k;
    }
  }
  cout << ans << '\n';
}