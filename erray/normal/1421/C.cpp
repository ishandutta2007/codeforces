// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  cout << 3 << '\n';
  cout << "R " << n - 1 << '\n';
  ++n;
  cout << "L " << n - 1 << '\n';
  cout << "L " << 2 << '\n';
}