#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  int all = N * (N + 1) / 2;
  for(int i = 1; i < all; i++) {
    if(__gcd(i, all - i) > 1) {
      cout << "Yes" << endl;
      vector< int > v, t;
      for(int j = N; j >= 1; j--) {
        if(i - j >= 0) {
          i -= j;
          v.emplace_back(j);
        } else {
          t.emplace_back(j);
        }
      }
      reverse(begin(v), end(v));
      reverse(begin(t), end(t));
      cout << v.size() << " ";
      for(int j : v) cout << j << " ";
      cout << endl;
      cout << t.size() << " ";
      for(int j : t) cout << j << " ";
      cout << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}