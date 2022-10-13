#include <bits/stdc++.h>
using namespace std;
const int A = 500;
const int S = 1 << 9;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> id(A + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    id[a[i]].push_back(i);
  }

  vector<vector<int>> f(n);
  vector<int> minX(S, oo), cur(A + 1);
  for (int i = 0; i < n; i++)
  {
    f[i].push_back(a[i]);
    for (int s : f[i])
      if (a[i] < minX[s])
      {
        minX[s] = a[i];
        for (int x = a[i] + 1; x <= A; x++)
          if (cur[x] < size(id[x]))
          {
            int ss = s ^ x, curId = id[x][cur[x]];
            if (minX[ss] > x)
              f[curId].push_back(ss);
          }
      }

    cur[a[i]]++;
  }

  vector<int> ans = {0};
  for (int i = 1; i < S; i++)
    if (minX[i] < oo)
      ans.push_back(i);

  cout << size(ans) << endl;
  for (int x : ans)
    cout << x << ' ';
}