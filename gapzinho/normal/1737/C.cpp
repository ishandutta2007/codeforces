#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
// using i4 = tuple<int, int, int, int>;
using i4 = pair<ii, ii>;
using ll = long long;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 2e5+5;

vector<int> v;

int sqr(int l) {
  int lo = 0, hi = 1e9+5;
  while(lo < hi) {
    int mi = (lo+hi+1)/2;
    if(mi*mi <= l) {
      lo = mi;
    } else {
      hi = mi-1;
    }
  }
  int cnt = lo*3-2;
  if(lo*(lo+1) <= l) cnt++;
  if(lo*(lo+2) <= l) cnt++;;
  return cnt;
}

int n;

bool border(int a, int b) {
  if(a != 1 && a != n) return false;
  if(b != 1 && b != n) return false;
  return true;
}
void solve() {
  cin >> n;
  int r1, c1, r2,  c2, r3, c3;
  int qntc1 = 0, qntc2 = 0;
  cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
  int x, y;
  cin >> x >> y;
  if(border(r1, c1) || border(r2, c2) || border(r3, c3)) {
    if(border(r2, c2)) {
      swap(r2, r1); swap(c2, c1);
    }
    if(border(r3, c3)) {
      swap(r3, r1); swap(c3, c1);
    }
    if(r2 == r1 || c2 == c1) {
      if(r3 == r1 || c3 == c1) {

        if(x == r1 || y == c1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
        return;
      }
    }
  }
  int x2, y2;
  if((r1+c1) % 2) qntc2++;
  else qntc1++;
  if((r2+c2) % 2) qntc2++;
  else qntc1++;
  if((r3+c3) % 2) qntc2++;
  else qntc1++;
  if(qntc1 == 2) {
    if((r1+c1) % 2 == 1) {
      x2 = r1;
      y2 = c1;
    }
    if((r2+c2) % 2 == 1) {
      x2 = r2;
      y2 = c2;
    }
    if((r3+c3) % 2 == 1) {
      x2 = r3;
      y2 = c3;
    }
    if((x+y) % 2 == 0) {
      cout << "YES\n";
      return;
    }
  } else {
    if((r1+c1) % 2 == 0) {
      x2 = r1;
      y2 = c1;
    }
    if((r2+c2) % 2 == 0) {
      x2 = r2;
      y2 = c2;
    }
    if((r3+c3) % 2 == 0) {
      x2 = r3;
      y2 = c3;
    }
    if((x+y) % 2 == 1) {
      cout << "YES\n";
      return;
    }
  }
  if((x2-x) % 2 == 0 && (y2-y) % 2 == 0) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int i = 1; i <= 500; i++) {
    
  }
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}