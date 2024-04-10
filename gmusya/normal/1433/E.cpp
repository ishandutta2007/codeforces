#include <iostream>
#include <vector>

typedef unsigned long long ull;

using namespace std;

int main() {
  vector <ull> fact(21);
  fact[0] = 1;
  for (ull i = 1; i <= 20; i++)
    fact[i] = fact[i - 1] * i;
  ull n;
  cin >> n;
  ull ans = fact[n] / (fact[n / 2] * fact[n / 2]) / 2;
  ull f = fact[n / 2 - 1];
  cout << ans * f * f;
  return 0;
}