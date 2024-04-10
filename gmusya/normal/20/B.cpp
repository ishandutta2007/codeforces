#include <iostream>
#include <iomanip>
#include <math.h>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  if (!A) {
    if (!B) {
      if (!C)
        cout << -1;
      else
        cout << 0;
      return 0;
    }
    cout << 1 << '\n';
    cout << fsp(10) << (ld)-C / B;
    return 0;
  }
  ll D = B * B - 4 * A * C;
  if (D < 0) {
    cout << 0;
    return 0;
  }
  if (!D) {
    cout << 1 << '\n';
    cout << fsp(10) << (ld)-B / (2 * A);
    return 0;
  }
  cout << 2 << '\n';
  if (A < 0) {
    cout << fsp(10) << (ld) (-B + sqrt(D)) / (2 * A) << '\n';
    cout << fsp(10) << (ld) (-B - sqrt(D)) / (2 * A);
  } else {
    cout << fsp(10) << (ld) (-B - sqrt(D)) / (2 * A) << '\n';
    cout << fsp(10) << (ld) (-B + sqrt(D)) / (2 * A);
  }
  return 0;
}