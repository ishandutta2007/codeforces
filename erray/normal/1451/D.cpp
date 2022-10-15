// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    long long cur = 0;
    while ((cur + k) * (cur + k) * 2 <= n * n) {
      cur += k;
    }
    cout << (cur * cur + (cur + k) * (cur + k) <= n * n ? "Ashish" : "Utkarsh") << '\n';
  }    
}