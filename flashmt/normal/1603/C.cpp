#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

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
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    long long ans = 0;
    vector<pair<int, int>> f = {{a[n - 1], 1}};
    for (int i = n - 2; i >= 0; i--)
    {
      vector<pair<int, int>> newF = {{a[i], 1}};
      for (auto [value, ways] : f)
      {
        int op = (a[i] + value - 1) / value;
        ans = (ans + ways * (op - 1LL) % BASE * (i + 1)) % BASE;
        newF.push_back({a[i] / op, ways});
      }

      int cur = 1;
      for (int j = 1; j < size(newF); j++)
        if (newF[j].first < newF[cur - 1].first) newF[cur++] = newF[j];
        else newF[cur - 1].second = (newF[cur - 1].second + newF[j].second) % BASE;
      newF.resize(cur);
      swap(f, newF);
    }

    cout << ans << '\n';
  }
}