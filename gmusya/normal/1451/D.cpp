#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll sq(ll x) {
  return x * x;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll d, k;
    cin >> d >> k;
    ll L = 0, R = 1e6 / k;
    while (L != R) {
      ll M = (L + R) / 2;
      if (2 * sq(M * k) <= sq(d))
        L = M + 1;
      else
        R = M;
    }
    L--;
    if (sq(L * k) + sq((L + 1) * k) <= sq(d))
      cout << "Ashish\n";
    else
      cout << "Utkarsh\n";
  }
  return 0;
}