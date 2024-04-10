#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s)
{
  int n = s.size();
  for (int i = 0; i < n / 2; i++)
    if (s[i] != s[n - 1 - i])
      return 0;
  return 1;
}

int try1Cut(string a)
{
  int n = a.size();
  string b = a;
  for (int i = 0; i < n - 1; i++)
  {
    rotate(b.begin(), b.begin() + 1, b.end());
    if (b != a && isPalindrome(b))
      return 1;
  }
  return 0;
}

int main()
{
  string a;
  cin >> a;
  int n = a.size();
  
  int hasDifferentChar = 0;
  for (int i = 1; i < n / 2; i++)
    if (a[i] != a[i - 1])
      hasDifferentChar = 1;
  if (!hasDifferentChar) 
  {
    cout << "Impossible" << endl;
    return 0;
  }

  cout << (try1Cut(a) ? 1 : 2) << endl;
}