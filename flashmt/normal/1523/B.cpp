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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cout << n * 3 << '\n';
    for (int i = 1; i <= n; i += 2)
      for (int j = 0; j < 2; j++)
      {
        cout << "1 " << i << ' ' << i + 1 << '\n';
        cout << "2 " << i << ' ' << i + 1 << '\n';
        cout << "1 " << i << ' ' << i + 1 << '\n';
      }
  }
}