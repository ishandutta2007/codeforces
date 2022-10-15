// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long t;
  string s;
  cin >> n >> t >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = 1 << (s[i] - 'a');
  }
  
  t += a[n - 2] - a[n - 1];
  n -= 2;

  a.erase(a.begin() + n, a.end());
  sort(a.rbegin(), a.rend());
  t -= accumulate(a.begin(), a.end(), 0LL);

  for (auto e : a) {
    e <<= 1;
    if (t + e <= 0) {
      t += e;
    }
  }

  cout << (t == 0 ? "Yes" : "No") << '\n';
}