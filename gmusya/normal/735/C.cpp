#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ll n;
  cin >> n;
  vector <ll> fib(200);
  fib[0] = 1, fib[1] = 1;
  for (int i = 2; i <= 199; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    if (fib[i] > n) {
      cout << i - 2;
      return 0;
    }
  }
  return 0;
}