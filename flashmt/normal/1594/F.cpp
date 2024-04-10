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
    long long s, n, k;
    cin >> s >> n >> k;
    if (k == 1) cout << (s < n * 2 ? "YES" : "NO") << '\n';
    else
    {
      long long q = s / (k * 2);
      long long cnt = q * k + min(s % (k * 2) + 1, k);
      cout << (n + 1 > cnt || s == k ? "YES" : "NO") << '\n';
    }
  }
}