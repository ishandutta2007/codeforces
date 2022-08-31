#include <bits/stdc++.h>
using namespace std;
int main(){
  int p, n;
  bool used[301] = {};

  cin >> p >> n;
  for(int i = 0, a; i < n; i++){
    cin >> a;
    if(used[a % p]++){
      cout << i + 1 << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
}