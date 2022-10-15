// author: erray
#include<bits/stdc++.h>
 
using namespace std;

vector<int> order(int n, function<bool(const int&, const int&)> f) {
  vector<int> res(n);
  iota(res.begin(), res.end(), 0);
  sort(res.begin(), res.end(), f);
  return res;
}
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    auto ord = order(n, [&](int x, int y) {
      return a[x] < a[y];
    });

    auto check = [&](int ch) {
      long long sum = 0;
      for (auto i : ord) {
        if (a[i] > ch) {
          sum += b[i];
        }
      }
      return (sum <= ch);
    };
    
    int low = 0, high = (int) 1e9;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (check(mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }   
    
    cout << low << '\n';
  }
}