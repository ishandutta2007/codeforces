#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int ms = 1005;

bool isPrime(ll a) {
  for(ll i = 2; i * i <= a; i++) {
    if(a % i == 0) return false;
  }
  return true;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    ll a, b;
    cin >> a >> b;
    if(a - b == 1 && isPrime(a+b)) cout << "YES\n";
    else cout << "NO\n";
  }
}