#include<bits/stdc++.h>
using namespace std;
void _(){
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for(int i = 0; i < n; i += 1) cin >> s[i];
  if(m & 1){
    cout << "YES\n";
    for(int k = 0; k <= m; k += 1) cout << (k & 1 ? 1 : 2) << " ";
    cout << "\n";
    return;
  }
  for(int i = 0; i < n; i += 1)
    for(int j = i + 1; j < n; j += 1) if(s[i][j] == s[j][i]){
      cout << "YES\n";
      for(int k = 0; k <= m; k += 1) cout << (k & 1 ? i + 1 : j + 1) << " ";
      cout << "\n";
      return;
    }
  for(int i = 0; i < n; i += 1){
    int x = -1, y = -1;
    for(int j = 0; j < n; j += 1){
      if(s[i][j] == 'a') x = j;
      if(s[i][j] == 'b') y = j;
    }
    if(x != -1 and y != -1){
      cout << "YES\n";
      for(int k = m / 2; k >= 1; k -= 1) cout << (k & 1 ? x + 1 : i + 1) << " ";
      cout << i + 1 << " ";
      for(int k = 1; k <= m / 2; k += 1) cout << (k & 1 ? y + 1 : i + 1) << " ";
      return;
    }
  }
  cout << "NO\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1) _();
  return 0;
}