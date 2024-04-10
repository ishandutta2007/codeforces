// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N = (int) 1e3;
  vector<int> p;
  vector<bool> ip(N, true);

  for (int i = 2; i < N; ++i) {
    if (!ip[i]) {
      continue;
    }

    p.push_back(i * i);
    for (int j = i; j < N; j += i) {
      ip[j] = false;
    }
  }

  cerr << (int) p.size() << '\n';
  
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];     
      for (auto e : p) {
        while (a[i] % e == 0) {
          a[i] /= e;
        }
      }
    }
    
    sort(a.begin(), a.end());
    int ans = 0;
    int ct = 0;
    for (int i = 0; i < n;) {
      int f = i;
      while (f < n && a[f] == a[i]) {
        ++f;
      }

      ans = max(ans, f - i);
      if ((f - i) % 2 == 0 || a[i] == 1) {
        ct += (f - i);
      }
      i = f;
    }

    int q;
    cin >> q;
    while (q--) {
      long long w;
      cin >> w;
      cout << (w ? max(ans, ct) : ans) << '\n';
    }
  }
}