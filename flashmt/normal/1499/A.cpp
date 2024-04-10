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
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    cout << (w <= (k1 + k2) / 2 && b <= (n * 2 - k1 - k2) / 2 ? "YES" : "NO") << '\n';
  }
}