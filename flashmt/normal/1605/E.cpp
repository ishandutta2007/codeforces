#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

void calc(vector<long long> &d)
{
  int n = size(d) - 1;
  for (int i = 1; i <= n; i++)
    for (int j = i * 2; j <= n; j += i)
      d[j] -= d[i];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  vector<long long> d0(n + 1);
  d0[1] = 1;
  calc(d0);

  vector<long long> d(n + 1);
  for (int i = 1; i <= n; i++)
    d[i] = b[i] - a[i];
  calc(d);
  long long initialAns = 0;
  for (int x : d)
    initialAns += abs(x);

  vector<long long> allD = {-oo};
  for (int i = 0; i <= n; i++)
    allD.push_back(d[i]);
  sort(begin(allD), end(allD));
  int sizeD = unique(begin(allD), end(allD)) - begin(allD);
  allD.resize(sizeD);
  int zeroId = find(begin(allD), end(allD), 0) - begin(allD);

  vector<long long> cntInc(sizeD), cntDec(sizeD);
  vector<long long> sumInc(sizeD), sumDec(sizeD);
  for (int i = 2; i <= n; i++)
  {
    int id = lower_bound(begin(allD), end(allD), d[i]) - begin(allD);
    if (d0[i] > 0)
    {
      cntInc[id]++;
      sumInc[id] += abs(d[i]);
    }
    else if (d0[i] < 0)
    {
      cntDec[id]++;
      sumDec[id] += abs(d[i]);
    }
  }

  for (int i = 1; i < sizeD; i++)
  {
    cntInc[i] += cntInc[i - 1];
    sumInc[i] += sumInc[i - 1];
    cntDec[i] += cntDec[i - 1];
    sumDec[i] += sumDec[i - 1];
  }

  auto get = [&](vector<long long> &arr, int from, int to)
  {
    return arr[to - 1] - (from ? arr[from - 1] : 0);
  };

  int q;
  cin >> q;
  while (q--)
  {
    int x;
    cin >> x;
    long long ans = initialAns;
    int diff = abs(x - b[1]);
    int posId = lower_bound(begin(allD), end(allD), diff) - begin(allD);
    int negId = upper_bound(begin(allD), end(allD), -diff) - begin(allD);

    if (x > b[1])
    {
      ans += (get(cntInc, zeroId, sizeD) - get(cntInc, 0, negId)) * diff;
      ans += (get(cntDec, 0, zeroId + 1) - get(cntDec, posId, sizeD)) * diff;
      if (diff >= 2)
      {
        ans += get(cntInc, negId, zeroId) * diff - get(sumInc, negId, zeroId) * 2;
        ans += get(cntDec, zeroId + 1, posId) * diff - get(sumDec, zeroId + 1, posId) * 2;
      }
    }
    else if (x < b[1])
    {
      ans += (get(cntDec, zeroId, sizeD) - get(cntDec, 0, negId)) * diff;
      ans += (get(cntInc, 0, zeroId + 1) - get(cntInc, posId, sizeD)) * diff;
      if (diff >= 2)
      {
        ans += get(cntDec, negId, zeroId) * diff - get(sumDec, negId, zeroId) * 2;
        ans += get(cntInc, zeroId + 1, posId) * diff - get(sumInc, zeroId + 1, posId) * 2;
      }
    }

    ans += abs(x - a[1]) - abs(b[1] - a[1]);
    cout << ans << '\n';
  }
}