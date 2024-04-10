#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int mod = 1e9+7;

const int ms = 2e5+3;

set<int> ihi, ilo;
set<int> hi, lo;

int p[ms];
int n;
int lstHi = -1, lstLo = -1;

void removeFromLo(int x);

void removeFromHi(int k) {
  hi.erase(k);
  lstHi = *hi.rbegin();
  // if(ihi.count(x))
  if(ihi.count(k)) ihi.erase(k);
  if(ilo.empty()) return;
  int x = *ilo.begin();
  auto it = hi.lower_bound(x);
  it--;
  int v = *it;
  if(v == -1 || p[x] > p[v]) {
    hi.emplace(x);
    lstHi = *hi.rbegin();
    // ilo.erase(x);
    // lo.erase(x);
    // lstLo = *lo.rbegin();
    removeFromLo(x);
  }
}

void removeFromLo(int k) {
  lo.erase(k);
  lstLo = *lo.rbegin();
  if(ilo.count(k)) ilo.erase(k);
  // assert(!ilo.count(k));
  if(ihi.empty()) return;
  int x = *ihi.begin();
  auto it = lo.lower_bound(x);
  it--;
  int v = *it;
  if(v == -1 || p[x] < p[v]) {
    lo.emplace(x);
    lstLo = *lo.rbegin();
    // ihi.erase(x);
    // hi.erase(x);
    // lstHi = *hi.rbegin();

    removeFromHi(x);
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  int r = 1;
  int ans = 0;
  hi.emplace(-1); lo.emplace(-1);
  for(int l = 1; l <= n; l++) {
    while(r <= n) {
      if(lstHi == -1 || lstLo == -1 || p[lstHi] < p[r] || p[lstLo] > p[r]) {
        if(lstHi != -1 && p[lstHi] > p[r]) {
          lo.emplace(r);
          lstLo = r;
          if(r != n && p[r] < p[r+1]) {
            ilo.emplace(r);
          }
        } else if(lstLo != -1 && p[lstLo] < p[r]) {
          lstHi = r;
          hi.emplace(r);
          if(r != n && p[r] > p[r+1]) {
            ihi.emplace(r);
          }
        } else {
          if(r == n || p[r] < p[r+1]) {
            lstHi = r;
            hi.emplace(r);
          } else {
            lo.emplace(r);
            lstLo = r;
          }
        }
        r++;
      } else {
        break;
      }
    }
    ans += r-l;
    if(hi.count(l)) {
      removeFromHi(l);
    } else {
      removeFromLo(l);
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}