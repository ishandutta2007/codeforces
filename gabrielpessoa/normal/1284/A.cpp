#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
 
const int ms = 2e6+5;
const int inf = 1e18;
const int mod = 998244353;

string s[ms], t[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> t[i];
  }
  int q;
  cin >> q;
  while(q--) {
    int i;
    cin >> i;
    i--;
    cout << s[i%n] << t[i%m] << '\n';
  }
}