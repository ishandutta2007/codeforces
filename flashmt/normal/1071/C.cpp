#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<pair<int, int>> ans;

  auto flip = [&](int x, int d)
  {
    ans.push_back({x, d});
    a[x] ^= 1;
    a[x - d] ^= 1;
    a[x + d] ^= 1;
  };

  while (n > 13)
  {
    int u = 0;
    vector<int> onesU, onesV;
    for (int i = n - 3; i < n; i++)
    {
      u = u * 2 + a[i];
      if (a[i])
        onesU.push_back(i);
    }
    for (int i = n - 6; i < n - 3; i++)
      if (a[i])
        onesV.push_back(i);

    if (u == 3) // 011
    {
      if (empty(onesV)) // 000011
      {
        flip(n - 2, 1);
        flip(n - 7, 4);
      }
      else if (size(onesV) == 1) // 001011
      {
        flip(onesV[0], n - 1 - onesV[0]);
        flip(n - 7, 5);
      }
      else if (size(onesV) == 2) // 011011
      {
        flip(onesV[0], n - 2 - onesV[0]);
        flip(onesV[1], n - 1 - onesV[1]);
      }
      else // 111011
      {
        flip(n - 4, 2);
        flip(n - 5, 4);
      }
      n -= 6;
    }
    else
    {
      if (u == 7) flip(n - 2, 1);
      else if (size(onesU) == 2) flip(onesU[0], onesU[1] - onesU[0]);
      else if (size(onesU) == 1) flip(n - 4, onesU[0] - n + 4);
      n -= 3;
    }
  }

  vector<int> moves;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= i; j++)
      if (i + j < n)
        moves.push_back((1 << i) | (1 << i - j) | (1 << i + j));

  vector<int> tr(1 << n, -1);
  tr[0] = 0;
  queue<int> q;
  q.push(0);
  while (!empty(q))
  {
    int x = q.front();
    q.pop();
    for (int m : moves)
    {
      int y = x ^ m;
      if (tr[y] < 0)
      {
        tr[y] = x;
        q.push(y);
      }
    }
  }

  int mask = 0;
  for (int i = 0; i < n; i++)
    mask |= a[i] << i;

  if (tr[mask] < 0)
  {
    cout << "NO" << endl;
    return 0;
  }

  while (mask)
  {
    int move = tr[mask] ^ mask;
    vector<int> bits;
    for (int i = 0; i < n; i++)
      if (move >> i & 1)
        bits.push_back(i);
    ans.push_back({bits[1], bits[1] - bits[0]});
    mask = tr[mask];
  }

  cout << "YES" << '\n';
  cout << size(ans) << '\n';
  for (auto [x, d] : ans)
    cout << x - d + 1 << ' ' << x + 1 << ' ' << x + d + 1 << '\n';
}