// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> left(n), right(n);
  int lst = 0;
  right[n - 1] = n - 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      lst = i;
    }
    left[i] = lst;
  }

  lst = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] < a[i + 1]) {
      lst = i;
    }
    right[i] = lst;
  }
  
  int big = 0;
  for (int i = 0; i < n; ++i) {
    left[i] = i - left[i];
    right[i] = right[i] - i;
    big = max({big, left[i], right[i]});
  }
  int ct = 0;
  bool ok = false;
  for (int i = 0; i < n; ++i) {
    if (left[i] == big && right[i] == big) {
      ok = true;
    }

    if (left[i] == big || right[i] == big) {
      ++ct;
    }
  }
  cout << (ok && ct == 1 && big % 2 == 0) << '\n';
}