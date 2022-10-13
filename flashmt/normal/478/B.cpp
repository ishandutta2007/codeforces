#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  long long maxPair = (n - m + 1LL) * (n - m) / 2;
  long long minPair = (n / m) * (n / m - 1LL) / 2 * (m - n % m) + (n / m) * (n / m + 1LL) / 2 * (n % m);
  cout << minPair << ' ' << maxPair << endl; 
}