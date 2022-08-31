#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long k, a, b;
  cin >> k >> a >> b;

  long long mod1 = a % k, mod2 = b % k;
  if((a < k && b < k) || (a < k && mod2 != 0) || (b < k && mod1 != 0)) {
    cout << -1 << endl;
  } else {
    cout << a / k + b / k << endl;
  }
}