#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  bool flag = true;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      flag = false;
  if (flag) {
    cout << 1 << '\n';
  } else {
    flag = true;
    for (int i = 2; i * i <= (n - 2); i++)
      if ((n - 2) % i == 0)
        flag = false;
    if (n % 2 && !flag)
      cout << 3 << '\n';
    else
      cout << 2 << '\n';
  }
  return 0;
}