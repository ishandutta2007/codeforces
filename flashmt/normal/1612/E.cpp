#include <bits/stdc++.h>
using namespace std;
const int M = 2e5;
const int K = 20;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(M, vector<int>(K + 1));
  for (int i = 0; i < n; i++)
  {
    int m, k;
    cin >> m >> k;
    a[--m][k]++;
  }

  vector<long long> sumA(M);
  set<pair<long long, int>> s;
  long long curSum = 0;
  for (int i = 0; i < M; i++)
  {
    for (int j = 1; j <= K; j++)
      sumA[i] += a[i][j] * j;
    s.insert({sumA[i], i});
    curSum += sumA[i];
  }

  int bestT = 0;
  double ans = 0;
  vector<int> bestIds, large(M);
  for (int t = K; t; t--)
  {
    if (t < K)
      for (int i = 0; i < M; i++)
      {
        s.erase({sumA[i], i});
        large[i] += a[i][t + 1];
        sumA[i] -= large[i];
        s.insert({sumA[i], i});
      }

    curSum = 0;
    auto u = rbegin(s);
    vector<int> curIds;
    for (int i = 0; i < t; i++)
    {
      curSum += u->first;
      curIds.push_back(u->second);
      u++;
    }

    if (1. * curSum / t > ans)
    {
      ans = 1. * curSum / t;
      bestT = t;
      bestIds = curIds;
    }
  }

  cout << bestT << endl;
  for (int x : bestIds)
    cout << x + 1 << ' ';
}