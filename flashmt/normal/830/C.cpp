#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  long long sumA = accumulate(begin(a), end(a), 0LL);

  vector<long long> cand;
  for (int x : a)
    for (int i = 1; i * i <= x; i++)
    {
      cand.push_back(i);
      cand.push_back((x + i - 1) / i);
    }
  sort(begin(cand), end(cand));
  cand.resize(unique(begin(cand), end(cand)) - begin(cand));
  cand.push_back(sumA + k + 1);

  long long ans = 1;
  for (int i = 0; i + 1 < size(cand); i++)
  {
    long long sumCeiling = 0;
    for (int x : a)
      sumCeiling += (x + cand[i] - 1LL) / cand[i];
    long long bound = (sumA + k) / sumCeiling;
    if (bound >= cand[i])
      ans = max(ans, min(bound, cand[i + 1] - 1));
  }

  cout << ans << endl;
}