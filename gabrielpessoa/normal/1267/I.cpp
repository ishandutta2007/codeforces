#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 2e6+5;

int fat[20];

ii query(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  string s;
  cin >> s;
  return s[0] == '>' ? ii(i, j) : ii(j, i);
}

int solve(int n) {
  ii x = query(1, 2);
  int z = 3;
  vector<int> left;
  for(int i = 4; i <= 2*n; i++) {
    ii y = query(z, i);
    ii result = query(x.second, y.second);
    if(y.second == result.first) swap(x, y);
    z = y.first;
    left.push_back(result.second);
  }
  for(int i = 0; i < left.size(); i++) {
    for(int j = i+1; j < left.size(); j++) {
      query(left[i], left[j]);
    }
  }
  cout << "!" << endl;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    solve(n);
  }
}