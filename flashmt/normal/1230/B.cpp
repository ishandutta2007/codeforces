#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++)
  {
    int smallest = !i && n > 1, digit = s[i] - '0';
    if (digit != smallest && k)
    {
      k--;
      cout << smallest;
    }
    else cout << digit;
  }
}