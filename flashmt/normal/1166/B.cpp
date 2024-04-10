#include <bits/stdc++.h>
using namespace std;
const string VOWELS = "aeiou";

int main()
{
  int k;
  cin >> k;
  for (int m = 5; m * m <= k; m++)
    if (k % m == 0)
    {
      int n = k / m;
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          cout << VOWELS[(i + j) % 5];
      return 0;
    }

  cout << -1 << endl;
}