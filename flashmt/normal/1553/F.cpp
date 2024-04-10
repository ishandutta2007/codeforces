#include <bits/stdc++.h>
using namespace std;
const int A = 300000;

// 1-indexed
template<typename T>
struct FenwickTree
{
  int n;
  vector<T> tree;

  FenwickTree(int n): n(n)
  {
    tree = vector<T>(n + 1);
  }

  void add(int x, T v)
  {
    for (int i = x; i <= n; i += i & -i)
      tree[i] += v;
  }

  T get(int x)
  {
    T res = 0;
    for (int i = x; i; i -= i & -i)
      res += tree[i];
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  FenwickTree<long long> cnt(A), sum(A), offset(A);
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    ans += sum.get(x - 1); // small % x
    ans += cnt.get(x - 1) * x - offset.get(x); // x % small
    ans += (i - 1 - cnt.get(x)) * x; // x % big
    for (int j = x; j <= A; j += x)
    {
      ans += sum.get(min(A, j + x - 1)) - sum.get(j - 1) - (cnt.get(min(A, j + x - 1)) - cnt.get(j - 1)) * j; // big % x;
      offset.add(j, x);
    }
    cnt.add(x, 1);
    sum.add(x, x);

    cout << ans << " \n"[i == n];
  }
}