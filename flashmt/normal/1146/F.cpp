#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, p[200200];
vector<int> a[200200];
long long fDone[200200], fUp[200200];

void dfs(int x)
{
  if (a[x].empty())
  {
    fDone[x] = fUp[x] = 1;
    return;
  }

  long long sumUp = 0;
  fDone[x] = 1;
  for (int y : a[x])
  {
    dfs(y);
    fUp[x] = ((fUp[x] + sumUp) * fUp[y] + fUp[x] * fDone[y]) % BASE;
    sumUp = (sumUp * fDone[y] + fUp[y] * fDone[x]) % BASE;
    fDone[x] = fDone[x] * fDone[y] % BASE;
  }

  fDone[x] = (fDone[x] + fUp[x]) % BASE;
  fUp[x] = (fUp[x] + sumUp) % BASE;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> p[i];
    a[--p[i]].push_back(i);
  }

  dfs(0);
  cout << fDone[0] << endl;
}