#include <iostream>
#include <algorithm>

using namespace std;

int sqr(int a) {
  return a * a;
}

int main() {
  int A1, B1, C1, A2, B2, C2;
  cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2;
  if (!A1 && !B1 && C1) {
    cout << 0;
    return 0;
  }
  if (!A2 && !B2 && C2) {
    cout << 0;
    return 0;
  }
  if (!A1 && !B1 && !C1) {
    cout << -1;
    return 0;
  }
  if (!A2 && !B2 && !C2) {
    cout << -1;
    return 0;
  }
  int g1 = __gcd(A1, B1);
  int g2 = __gcd(A2, B2);
  if (A1 / g1 == A2 / g2 && B1 / g1 == B2 / g2) {
    if (C1 * g2 == C2 * g1)
      cout << -1;
    else
      cout << 0;
    return 0;
  }
  cout << 1;
  return 0;
}