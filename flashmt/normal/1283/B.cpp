#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    cout << min(n, n / k * k + k / 2) << '\n';
  }
}