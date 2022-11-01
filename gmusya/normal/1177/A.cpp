#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ll k;
  cin >> k;
  ll digits = 1, numbers = 9;
  ll first = 1;
  while (true) {
    if (digits * numbers >= k)
      break;
    k -= digits * numbers;
    first *= 10;
    digits++;
    numbers = 10 * numbers;
  }
  first += (k - 1) / digits;
  ll kek = digits - (k - 1) % digits - 1;
  while (kek--)
    first /= 10;
  cout << first % 10;
  return 0;
}