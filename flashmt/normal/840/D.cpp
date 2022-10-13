#include <bits/stdc++.h>
using namespace std;
const int K = 2000;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
  }

  vector<int> queryCnt(n + 1), ans(q, oo);
  vector<vector<tuple<int, int, int>>> queries(n + 1);
  for (int iq = 0; iq < q; iq++)
  {
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    int target = (r - l) / k;
    if (r - l > K) queries[r].push_back({l, target, iq});
    else
    {
      for (int i = l + 1; i <= r; i++)
        if (++queryCnt[a[i]] > target)
          ans[iq] = min(ans[iq], a[i]);
      for (int i = l + 1; i <= r; i++)
        queryCnt[a[i]] = 0;
    }
  }

  vector<int> curCnt(n + 1);
  for (int i = 1; i <= n; i++)
    if (cnt[i] * 5 > K)
      for (int j = 1; j <= n; j++)
      {
        curCnt[j] = curCnt[j - 1] + (a[j] == i);
        for (auto [l, target, id] : queries[j])
          if (curCnt[j] - curCnt[l] > target && ans[id] == oo)
            ans[id] = i;
      }

  for (int x : ans)
    cout << (x == oo ? -1 : x) << '\n';
}