#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n;
  while (n--)
  {
    cin >> x;
    if (x)
    {
      cout << "HARD" << endl;
      return 0;
    }
  }
  cout << "EASY" << endl;
}