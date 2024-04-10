#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int BASE = 998244353;

template<typename T>
struct FenwickTree
{
  int n, indexBase;
  vector<T> a;

  FenwickTree(int n, int indexBase = 1): n(n), indexBase(indexBase)
  {
    a = vector<T>(n + 1, 0);
  }

  void add(int x, T v)
  {
    for (int i = x + 1 - indexBase; i <= n; i += i & -i)
      a[i] = (a[i] + v) % BASE;
  }

  T get(int x)
  {
    T res = 0;
    for (int i = x + 1 - indexBase; i; i -= i & -i)
      res = (res + a[i]) % BASE;
    return res;
  }
};

int n, x[N], y[N], active[N];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> active[i];

  FenwickTree<int> tree(n, 0);
  long long ans = (x[n - 1] + 1) % BASE;
  for (int i = n - 1; i >= 0; i--)
  {
    int cnt = (tree.get(i) + active[i]) % BASE;
    ans = (ans + 1LL * cnt * (x[i] - y[i])) % BASE;
    int j = lower_bound(x, x + n, y[i]) - x;
    if (j < i)
      tree.add(j, cnt);
  }

  cout << ans << endl;
}