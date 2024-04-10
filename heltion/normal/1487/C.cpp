#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1)
      for(int j = i + 1; j < n; j += 1){
        if((j - i) * 2 == n) cout << "0 ";
        else if((j - i) * 2 < n) cout << "1 ";
        else cout << "-1 ";
      }
    cout << "\n";
  }
  return 0;
}