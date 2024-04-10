#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (a > b)
    swap(a, b);
  if (b > c)
    swap(b, c);
  if (a > b)
    swap(a, b);
  cout << min(a + b, (a + b + c) / 3);
  return 0;
}