#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    string s;
    cin >> s;

    int sum = 0, even = 0, hasZero = 0;
    for (char c : s)
    {
      int x = c - '0';
      sum += x;
      if (x % 2 == 0)
        even++;
      if (!x)
        hasZero = 1;
    }

    cout << (hasZero && even >= 2 && sum % 3 == 0 ? "red" : "cyan") << endl;
  }
}