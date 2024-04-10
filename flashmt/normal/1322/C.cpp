#include <bits/stdc++.h>
using namespace std;
const int BASE = 989991077;
const int P = 67;

int main()
{
  vector<long long> h(5e5);
  h[0] = 1;
  for (int i = 1; i < size(h); i++)
    h[i] = h[i - 1] * P % BASE;

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<long long> c(n);
    for (int i = 0; i < n; i++)
      cin >> c[i];

    vector<long long> sumLeft(n), hash(n);
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      sumLeft[--x] += c[--y];
      hash[y] = (hash[y] + h[x]) % BASE;
    }

    map<int, long long> sumRight;
    for (int i = 0; i < n; i++)
      if (hash[i])
        sumRight[hash[i]] += c[i];

    long long ans = accumulate(begin(sumLeft), end(sumLeft), 0LL, [](long long u, long long v) { return gcd(u, v); });
    ans = accumulate(begin(sumRight), end(sumRight), ans, [](long long u, pair<long long, long long> v) { return gcd(u, v.second); });
    cout << ans << '\n';
  }
}