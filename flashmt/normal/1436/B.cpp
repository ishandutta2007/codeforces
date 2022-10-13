#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    a[0] = a[1] = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cout << a[(i + j) % n] << " \n"[j == n - 1];
  }
}