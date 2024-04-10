#include <bits/stdc++.h>
using namespace std;
const int BLOCK = 10;

int ask(int l, int r)
{
  cout << "? " << l + 1 << ' ' << r + 1 << endl;
  cout.flush();
  int res;
  cin >> res;
  return r - l + 1 - res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  int numBlock = (n + BLOCK - 1) / BLOCK;
  vector<int> blocks;

  for (int it = 0; it < t; it++)
  {
    int k;
    cin >> k;
    if (!it)
      for (int i = 0; i < numBlock; i++)
        blocks.push_back(ask(i * BLOCK, min(n, (i + 1) * BLOCK) - 1));

    int sum = 0;
    for (int i = 0; i < numBlock; i++)
      if (sum + blocks[i] < k) sum += blocks[i];
      else
      {
        int low = i * BLOCK, high = min(n, low + BLOCK) - 1, res = high;
        while (low <= high)
        {
          int mid = (low + high) / 2;
          if (ask(0, mid) < k) low = mid + 1;
          else
          {
            res = mid;
            high = mid - 1;
          }
        }
        cout << "! " << res + 1 << endl;
        cout.flush();
        blocks[i]--;
        break;
      }
  }
}