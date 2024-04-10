// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto ask = [&](int x) {
    cout << "? " << x + 1 << endl;
    int res;
    cin >> res;
    return res;
  };
  
  int Block = sqrt(n) - 1;
  for (int i = 0; i < Block; ++i) {
    ask(0);
  }

  int ind = 0;
  while (ask(ind) == k) {
    ind += Block;
  }

  if (ask(ind) > k) {
    while (true) {
      int next = (ind - Block + n) % n;
      if (ask(next) <= k) {
        break;
      }
      ind = next;
    }

    while (ask(ind) != k) {
      ind = (ind - 1 + n) % n;
    }

  } else {
    while (true) {
      int next = (ind + Block) % n;
      if (ask(next) >= k) {
        break;
      }
      ind = next;
    }

    while (ask(ind) != k) {
      ind = (ind + 1) % n;
    }
  }
  cout << "! " << ind + 1 << endl;
}