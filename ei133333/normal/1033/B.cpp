#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

bool is_prime(int64 x) {
  for(int64 i = 2; i * i <= x; i++) {
    if(x % i == 0) return false;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int64 X, Y;
    cin >> X >> Y;
    if(Y + 1 == X && is_prime(X + Y)) cout << "YES\n";
    else cout << "NO\n";
  }
}