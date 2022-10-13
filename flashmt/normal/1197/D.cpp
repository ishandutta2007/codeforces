#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 50;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k, x;
  vector<long long> a(1, 0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    a.push_back(a.back() + x);
  }

  vector<long long> minVal(m, oo);
  minVal[0] = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    long long val = a[i] - 1LL * i / m * k;
    for (int j = 0; j < m; j++)
      ans = max(ans, val - minVal[j] - (i % m > j) * k);
    minVal[i % m] = min(minVal[i % m], val);
  }

  cout << ans << endl;
}