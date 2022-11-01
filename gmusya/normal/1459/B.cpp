#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int k = (n + 1) / 2;
  if (n % 2) {
    k = 2 * k + 1;
    cout << k * k / 2;
  } else {
    k++;
    cout << k * k;
  }
  return 0;
}