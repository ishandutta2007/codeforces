#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n;
  cin >> n;
  vector<int> digits;
  while (n)
  {
    digits.push_back(n % 10);
    n /= 10;
  }

  int ans = 0, carry = 0;
  for (int i = 0; i < digits.size(); i++)
  {
    int digit = digits[i] - carry;
    if (i == digits.size() - 1 || digit == 9)
    {
      ans += digit;
      carry = 0;
    }
    else
    {
      ans += digit + 10;
      carry = 1;
    }
  }

  cout << ans << endl;
}