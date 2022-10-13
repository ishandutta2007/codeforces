#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;
    for (int i = 0, sumXor = 0; i < n; i++)
    {
      int x = i ^ sumXor;
      cout << x << endl;
      cout.flush();
      int resp;
      cin >> resp;
      if (resp)
        break;
      sumXor ^= x;
    }
  }
}