#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111222;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, a[88][88];
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  int ans = oo;
  for (int turn = 0; turn < 11111; turn++)
  {
    vector<int> nodes[2];
    nodes[0].push_back(0);
    for (int i = 1; i < n; i++)
      nodes[rand() % 2].push_back(i);

    vector<int> f(n, oo);
    f[0] = 0;
    for (int i = 1; i <= k; i++)
    {
      vector<int> newF(n, oo);
      for (int x : nodes[1 - i % 2])
        for (int y : nodes[i % 2])
          newF[y] = min(newF[y], f[x] + a[x][y]);
      swap(f, newF);
    }

    ans = min(ans, f[0]);
  }

  cout << ans << endl;
}