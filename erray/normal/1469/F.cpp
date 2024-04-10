// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());
  const int M = (int) 1e6;
  vector<int> ct(M + 3);
  ct[0] = 1;
  ct[1] = -1;

  int p =  0;
  int now = 0;

  for (int i = 0; i < M; ++i) {
    now += ct[i];
    ct[i + 1] += ct[i];
    if (now + ct[i + 1] >= k) {
      return cout << i + 1, 0;
    }      

    while (ct[i] > 0 && p < n) {
      ct[i + 2] += 2;
      ct[i + 2 + (a[p] - 1) / 2] -= 1;
      ct[i + 2 + (a[p] - 1) / 2 + (a[p] % 2 == 0)] -= 1;
      ++p;
      --ct[i];
      --now;
    }
  }

  cout << -1 << '\n';
}