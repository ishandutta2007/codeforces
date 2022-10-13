#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  string t;
  cin >> n >> k >> t;

  vector<int> last(k, -1);
  for (int i = 0; i < size(t); i++)
    last[t[i] - 'a'] = i;

  vector<int> id(k);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int u, int v) { return last[u] < last[v]; });
  for (int i = 0; i < n; i++)
    t += char('a' + id[i % k]);

  vector<long long> f(k);
  long long sumF = 1;
  for (int i = 0; i < size(t); i++)
  {
    int c = t[i] - 'a';
    long long curF = sumF;
    if (last[c] >= 0)
      sumF = (sumF - f[c] + BASE) % BASE;
    f[c] = curF;
    sumF = (sumF + curF) % BASE;
    last[c] = i;
  }

  cout << sumF << endl;
}