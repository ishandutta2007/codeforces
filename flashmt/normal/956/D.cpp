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
  int n, w;
  cin >> n >> w;
  vector<pair<double, double>> pos, neg;
  vector<double> allT;
  for (int i = 0; i < n; i++)
  {
    int x, v;
    cin >> x >> v;
    double minT = 1. * abs(x) / (abs(v) + w);
    double maxT = 1. * abs(x) / (abs(v) - w);
    if (x < 0) neg.push_back({minT, maxT});
    else pos.push_back({minT, maxT});
    allT.push_back(minT);
    allT.push_back(maxT);
  }

  sort(begin(allT), end(allT));
  int cntT = unique(begin(allT), end(allT)) - begin(allT);
  allT.resize(cntT);

  auto cmp = [&](pair<double, double> u, pair<double, double> v)
  {
    return u.first != v.first ? u.first < v.first : u.second > v.second;
  };
  sort(begin(pos), end(pos), cmp);
  sort(begin(neg), end(neg), cmp);

  auto calcSame = [&](vector<pair<double, double>> &segs)
  {
    long long res = 0;
    FenwickTree<long long> tree(cntT, 0);
    for (int i = 0; i < size(segs); i++)
    {
      int r = lower_bound(begin(allT), end(allT), segs[i].second) - begin(allT);
      res += i;
      if (r)
        res -= tree.get(r - 1);
      tree.add(r, 1);
    }
    return res;
  };

  long long ans = calcSame(pos) +  calcSame(neg);

  vector<int> cntPosL(cntT + 1), cntPosR(cntT + 1);
  for (auto [l, r] : pos)
  {
    int idL = lower_bound(begin(allT), end(allT), l) - begin(allT);
    int idR = lower_bound(begin(allT), end(allT), r) - begin(allT);
    cntPosL[idL]++;
    cntPosR[idR]++;
  }

  for (int i = 1; i < cntT; i++)
    cntPosR[i] += cntPosR[i - 1];
  for (int i = cntT - 2; i >= 0; i--)
    cntPosL[i] += cntPosL[i + 1];

  ans += 1LL * size(pos) * size(neg);
  for (auto [l, r] : neg)
  {
    int idL = lower_bound(begin(allT), end(allT), l) - begin(allT);
    int idR = lower_bound(begin(allT), end(allT), r) - begin(allT);
    if (idL)
      ans -= cntPosR[idL - 1];
    if (idR + 1 < cntT)
      ans -= cntPosL[idR + 1];
  }

  cout << ans << endl;
}