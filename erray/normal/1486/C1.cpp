// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto ask = [&](int l, int r) {
    assert(l != r);
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int res;
    cin >> res;
    --res;
    return res;
  };

  int bef = ask(0, n - 1);
  int ans = -1;
  if (bef != 0 && ask(0, bef) == bef) {
    int low = 0, high = bef - 1;
    while (low < high) {
      int mid = 1 + ((low + high) >> 1);
      if (ask(mid, bef) == bef) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    ans = low;
  } else {
    int low = bef + 1, high = n - 1;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (ask(bef, mid) == bef) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }    

    ans = low;
  }

   cout << "! " << ans + 1 << endl;
}