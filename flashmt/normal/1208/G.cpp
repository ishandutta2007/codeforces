#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, phi[1000100];
  cin >> n >> k;

  for (int i = 2; i <= n; i++)
    phi[i] = i;

  for (int i = 2; i <= n; i++)
    if (phi[i] == i)
      for (int j = i; j <= n; j += i)
        phi[j] = phi[j] / i * (i - 1);

  vector<pair<int, int>> p;
  for (int i = 3; i <= n; i++)
    p.push_back({phi[i], i});
  sort(p.begin(), p.end());

  long long ans = 1;
  int hasEven = 0;
  for (int i = 0; i < k; i++)
  {
    ans += p[i].first;
    hasEven |= p[i].second % 2 == 0;
  }

  cout << ans + hasEven << endl;
}