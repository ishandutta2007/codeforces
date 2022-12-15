#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 2005;

int notPrime[ms];
int vis[ms];

main() {
  for(int i = 2; i < ms; i++) {
    if(notPrime[i]) continue;
    for(int j = i+i; j < ms; j += i) {
      notPrime[j] = 1;
    }
  }
  int n;
  cin >> n;
  int m = n;
  while(notPrime[m]) m++;
  cout << m << '\n';
  for(int i = 0; i < n; i++) {
    cout << i+1 << ' ' << (i+1)%n + 1 << '\n';
  }
  m -= n;
  for(int i = 0; i < n && m; i++) {
    int j = (i+2) % n;
    if(!vis[i] && !vis[j]) {
      vis[i] = 1; vis[j] = 1;
      cout << i + 1 << ' ' << j + 1 << '\n';
      m--;
    }
  }
  //assert(m == 0);
}