#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  int n, x, c, sum = 0;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    sum += c;
  }
  if (sum < 0)
    sum = -sum;
  if (sum % x)
    cout << sum / x + 1 << endl;
  else
    cout << sum / x << endl;
  return 0;
}