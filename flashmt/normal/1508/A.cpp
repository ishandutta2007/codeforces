#include <bits/stdc++.h>
using namespace std;

string a[3];
int n, cnt[3][2];
vector<int> id[3][2];

void solve()
{
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++)
      for (int k = 0; k < 2; k++)
        if (cnt[i][k] >= n && cnt[j][k] >= n)
        {
          int p = 0, q = 0;
          for (int z = 0; z < min(cnt[i][k], cnt[j][k]); z++)
          {
            while (p < id[i][k][z])
              cout << a[i][p++];
            while (q < id[j][k][z])
              cout << a[j][q++];
            cout << k;
            p++;
            q++;
          }
          while (p < n * 2)
            cout << a[i][p++];
          while (q < n * 2)
            cout << a[j][q++];
          cout << '\n';
          return;
        }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
      cin >> a[i];
      cnt[i][0] = cnt[i][1] = 0;
      id[i][0].clear();
      id[i][1].clear();
      for (int j = 0; j < n * 2; j++)
      {
        int x = a[i][j] - '0';
        cnt[i][x]++;
        id[i][x].push_back(j);
      }
    }

    solve();
  }
}