#include <bits/stdc++.h>
using namespace std;

void check(int q, int n, int k)
{
  if (k * q < n)
    return;
  int rem = k * q - n;
  if (rem % 2)
    return;

  vector<int> cnt(n);
  int maxUse = q - 1;
  if (maxUse % 2)
    maxUse--;
  for (int i = 0; i < n; i++)
  {
    cnt[i] = min(rem, maxUse);
    rem -= cnt[i];
    cnt[i]++;
  }

  if (rem)
    return;

  int ans = 0;
  for (int turn = 0; turn < q; turn++)
  {
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
      a.push_back({cnt[i], i});
    sort(a.begin(), a.end(), greater<pair<int, int>>());

    cout << '?';
    for (int i = 0; i < k; i++)
    {
      int id = a[i].second;
      assert(cnt[id] > 0);
      cnt[id]--;
      cout << ' ' << id + 1;
    }
    cout << endl;
    cout.flush();
    int res;
    cin >> res;
    ans ^= res;
  }

  cout << "! " << ans << endl;
  cout.flush();
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int q = 1; q <= 500; q++)
    check(q, n, k);
  cout << -1 << endl;
  cout.flush();
}