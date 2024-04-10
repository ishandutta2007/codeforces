#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<vector<int>> p(155);
  p[0] = {1};
  p[1] = {0, 1};
  for (int i = 2; i <= 150; i++)
  {
    p[i].resize(i + 1);
    for (int j = 0; j < i; j++)
      p[i][j + 1] = p[i - 1][j];

    set<int> coef;
    for (int j = 0; j < i - 1; j++)
      coef.insert(p[i][j] * p[i - 2][j]);

    assert(!(coef.count(1) && coef.count(-1)));
    int sign = coef.count(1) ? -1 : 1;
    for (int j = 0; j < i - 1; j++)
      p[i][j] += p[i - 2][j] * sign;
  }

  int n;
  cin >> n;
  for (int i : {n, n - 1})
  {
    cout << i << endl;
    for (int x : p[i])
      cout << x << ' ';
    cout << endl;
  }
}