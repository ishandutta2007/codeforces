// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    while (n % 2 == 0) {
      n /= 2;   
    }

    cout << (n == 1 ? "NO" : "YES") << '\n';
  }
}