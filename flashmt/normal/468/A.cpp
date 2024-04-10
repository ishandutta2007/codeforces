#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  
  if (n < 4) cout << "NO" << endl;
  else if (n % 2)
  {
    cout << "YES" << endl;
    cout << "5 - 1 = 4" << endl;
    cout << "4 - 2 = 2" << endl;
    cout << "2 * 3 = 6" << endl;
    cout << "6 * 4 = 24" << endl;
    for (int i = 7; i <= n; i += 2)
    {
      cout << i << " - " << i - 1 << " = 1\n";
      cout << "24 * 1 = 24\n";
    }
  }
  else
  {
    cout << "YES" << endl;
    cout << "1 * 2 = 2" << endl;
    cout << "2 * 3 = 6" << endl;
    cout << "6 * 4 = 24" << endl;
    for (int i = 6; i <= n; i += 2)
    {
      cout << i << " - " << i - 1 << " = 1\n";
      cout << "24 * 1 = 24\n";
    }
  }
}