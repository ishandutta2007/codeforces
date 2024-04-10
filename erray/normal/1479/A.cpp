// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto get = [&](int x) {
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
  };
  
  int low = 1, high = n;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (get(mid) < get(mid + 1)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << "! " << low << endl;
}