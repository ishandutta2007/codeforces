#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, disk, x;
  map<int, int> cnt;
  cin >> n >> disk;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    cnt[x]++;
  }

  int k = 1 << min(20, disk * 8 / n);
  if (k >= cnt.size())
  {
    cout << 0 << endl;
    return 0;
  }

  vector<int> sumCnt(1, 0);
  for (auto u : cnt)
    sumCnt.push_back(sumCnt.back() + u.second);

  int ans = 0;
  for (int i = k; i < sumCnt.size(); i++)
    ans = max(ans, sumCnt[i] - sumCnt[i - k]);
  cout << n - ans << endl;
}