#include <bits/stdc++.h>
using namespace std;

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
      a[i] += v;
  }

  T get(int x)
  {
    T res = 0;
    for (int i = x + 1 - indexBase; i; i -= i & -i)
      res += a[i];
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  FenwickTree<int> tree(n);
  int inv = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    inv ^= (i - tree.get(x)) & 1;
    tree.add(x, 1);
  }
  cout << (inv == n % 2 ? "Petr" : "Um_nik") << endl;
}