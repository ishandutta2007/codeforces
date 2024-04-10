#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long p, k;
  cin >> p >> k;
  long long cur = p;
  vector<long long> a;
  while (cur < 0 || cur >= k)
  {
    long long b = cur >= 0 ? -(cur / k) : (-cur + k - 1) / k;
    a.push_back(cur + b * k);
    cur = b;
  }
  a.push_back(cur);
  cout << size(a) << endl;
  for (auto x : a)
    cout << x << ' ';
}