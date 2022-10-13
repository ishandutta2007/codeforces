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
    int n, s;
    cin >> n >> s;
    n = (n - (n + 1) / 2 + 1);
    cout << s / n << '\n';
  }
}