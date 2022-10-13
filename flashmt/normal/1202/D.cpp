#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, n, v[50000] = {0};
  v[2] = 1;
  for (int i = 3; i < 50000; i++)
    v[i] = v[i - 1] + i - 1;

  cin >> test;
  while (test--)
  {
    cin >> n;
    vector<int> flag(50000, 0);
    for (int i = 49999; i >= 2; i--)
    {
      flag[i] = n / v[i];
      n -= flag[i] * v[i];
    }

    cout << 1;
    for (int i = 1; i < 50000; i++)
    {
      cout << 3;
      while (flag[i]--)
        cout << 7;
    }
    cout << endl;
  }
}