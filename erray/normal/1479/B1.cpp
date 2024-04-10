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
  
  vector<int> na;
  for (int i = 0; i < n; ++i) {
    if (i < 2 || a[i] != a[i - 1] || a[i] != a[i - 2]) {
      na.push_back(a[i]);
    }
  }

  swap(na, a);
  n = (int) a.size();

  int last = -1;
  int w = -1;
  int add = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && a[i] == a[i - 1]) {
      if (w == a[i]) {
        bool ok = false;
        for (int j = last + 1; j < i; ++j) {
          ok |= (j == 0 || a[j - 1] != a[j + 1]) && a[j] != w;
        }

        add += !ok;
      }

      w = a[i];
      last = i;
    }
  }

  cout << n - add << '\n';
}