#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, k, n, s, a[500500], cntB[500500] = {0};
  cin >> m >> k >> n >> s;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  for (int i = 0; i < s; i++)
  {
    int x;
    cin >> x;
    cntB[x]++;
  }

  int cntA[500500] = {0}, match = 0;
  int ans = m, from, to;
  for (int i = 0, j = 0; i < m; i++)
  {
    while (j < m && match < s)
    {
      cntA[a[j]]++;
      if (cntA[a[j]] <= cntB[a[j]])
        match++;
      j++;
    }

    if (match < s)
      break;

    int remove = i % k + max(0, j - i - k);
    if (remove + k * n <= m && remove < ans)
    {
      ans = remove;
      from = i;
      to = j;
    }

    cntA[a[i]]--;
    if (cntA[a[i]] < cntB[a[i]])
      match--;
  }

  if (ans == m) cout << -1 << endl;
  else
  {
    cout << ans << endl;
    for (int i = 0; i < from % k; i++)
      cout << i + 1 << ' ';

    memset(cntA, 0, sizeof cntA);
    vector<int> unmatch;
    for (int i = from; i < to; i++)
      if (cntA[a[i]] < cntB[a[i]]) cntA[a[i]]++;
      else unmatch.push_back(i + 1);
    assert(unmatch.size() >= ans);
    for (int i = 0; i < ans; i++)
      cout << unmatch[i] << ' ';
  }
}