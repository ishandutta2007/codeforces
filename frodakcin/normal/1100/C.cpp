#include <iostream>
#include <cstdio>

#include <cmath>
#include <iomanip>

using namespace std;

int N, R;

using ld = long double;
#define tld(X) static_cast<ld>(X)

ld PI = atanl(1) * 4;

int main() {
  scanf("%d%d", &N, &R);
  
  ld v = sinl(PI/N);
  cout << setprecision(9) << R*(v)/(1 - v) << "\n";
  
  return 0;
}