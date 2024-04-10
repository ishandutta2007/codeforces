#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct Trie
{
  vector<int> minV, maxV, ans;

  Trie(int low, int high, vector<int> &cnt)
  {
    minV = ans = vector<int>(high - low, oo);
    maxV = vector<int>(high - low, -oo);
    if (low + 1 == high)
    {
      if (cnt[low])
        minV[0] = maxV[0] = 0;
      return;
    }

    int mid = (low + high) / 2;
    Trie l(low, mid, cnt);
    Trie r(mid, high, cnt);
    int half = mid - low;
    for (int i = 0; i < half; i++)
    {
      minV[i] = min(l.minV[i], r.minV[i] + half);
      maxV[i] = max(l.maxV[i], r.maxV[i] + half);
      ans[i] = min(l.ans[i], r.ans[i]);
      ans[i] = min(ans[i], r.minV[i] + half - l.maxV[i]);
    }
    for (int i = 0; i < half; i++)
    {
      minV[i + half] = min(l.minV[i] + half, r.minV[i]);
      maxV[i + half] = max(l.maxV[i] + half, r.maxV[i]);
      ans[i + half] = min(l.ans[i], r.ans[i]);
      ans[i + half] = min(ans[i + half], l.minV[i] + half - r.maxV[i]);
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> cnt(1 << k);
  while (n--)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }

  Trie t(0, 1 << k, cnt);
  for (int x : t.ans)
    cout << x << ' ';
}