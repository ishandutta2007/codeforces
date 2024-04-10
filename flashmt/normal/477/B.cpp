#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  cout << (n * 6 - 1) * k << endl;
  for (int i = 0; i < n; i++)
  {
    cout << (i * 6 + 1) * k << ' ';
    cout << (i * 6 + 2) * k << ' ';
    cout << (i * 6 + 3) * k << ' ';
    cout << (i * 6 + 5) * k << '\n';
  }
}