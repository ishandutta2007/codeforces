#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 1005;

char m[ms][ms];
int eq[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, l, k;
  cin >> n >> l >> k;
  for(int i = 0; i < k-1; i++) eq[i] = 1;
  int curEq = 0;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int le = 0, ri = s.size() - 1;
  for(int i = 0; i < l; i++) {
    for(int j = 0; j < k-1; j++) {
      // cout << curEq << endl;
      if(eq[j]) m[j][i] = s[le++];
      else m[j][i] = s[ri-curEq+1+j];
    }
    ri -= curEq;
    m[k-1][i] = s[le++];
    curEq = k-1;
    for(int j = 0; j < k -1; j++) {
      if(m[k-1][i] != m[j][i]) eq[j] = 0;
      else if(eq[j]) curEq--;
    }
  }
  for(int i = k; i < n; i++) {
    for(int j = 0; j < l; j++) {
      // cout << i*l+j << " em " << i << ' ' << j << endl;
      m[i][j] = s[le++];
    }
  }
  // cout << n << ' ' << l << endl;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < l; j++) {
      // cout << "imprimindo " << i << ' ' << j <<  endl;
      cout << m[i][j];
    }
    cout << '\n';
  }
}