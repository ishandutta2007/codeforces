#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n, m, a[100];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cout << (accumulate(a, a + n, 0) == m ? "YES" : "NO") << endl;
  }
}