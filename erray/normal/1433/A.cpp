// author: erray
#include<bits/stdc++.h>
 
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int lg = int(log10(n)) + 1;
    cout << (n % 10 - 1) * 10 + lg * (lg + 1) / 2 << '\n';
  }
}