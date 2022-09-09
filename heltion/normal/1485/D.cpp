#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i += 1){
    for(int j = 0, a; j < m; j += 1){
      cin >> a;
      if((i + j) & 1) cout << 720720 + a * a * a * a << " ";
      else cout << 720720 << " ";
    }
    cout << "\n";
  }
  return 0;
}