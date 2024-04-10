#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k;
  cin >> k;
  if (!k) cout << "a" << endl;
  else
  {
    char c = 'a';
    for (int i = 500; i >= 2; i--)
    {
      int cost = i * (i - 1) / 2;
      if (cost > k)
        continue;
      int num = k / cost;
      k -= cost * num;
      while (num--)
      {
        for (int j = 0; j < i; j++)
          cout << c;
        c++;
      }
    }
    cout << endl;
  }
}