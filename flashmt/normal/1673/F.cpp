#include <bits/stdc++.h>
using namespace std;
const int N = 32;

int main()
{
  vector<int> rows(N), cols(N);
  for (int i = 0; i < N; i++)
  {
    int gray = i ^ (i >> 1);
    for (int j = 0; j < __lg(N); j++)
      if (gray >> j & 1)
      {
        rows[i] |= 1 << j * 2;
        cols[i] |= 1 << j * 2 + 1;
      }
  }

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 1; j++)
      cout << (cols[j] ^ cols[j + 1]) << " \n"[j == n - 2];
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n; j++)
      cout << (rows[i] ^ rows[i + 1]) << " \n"[j == n - 1];
  cout.flush();

  int s = 0;
  while (k--)
  {
    int x;
    cin >> x;
    s ^= x;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if ((rows[i] ^ cols[j]) == s)
        {
          cout << i + 1 << ' ' << j + 1 << endl;
          cout.flush();
        }
  }
}