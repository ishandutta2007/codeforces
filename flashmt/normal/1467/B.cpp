#include <bits/stdc++.h>
using namespace std;

int n, a[300300];

int check(int i)
{
  if (i < 1 || i > n - 2)
    return 0;
  return a[i] < min(a[i - 1], a[i + 1]) || a[i] > max(a[i - 1], a[i + 1]);
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
    for (int i = 0; i < n; i++)
      cin >> a[i];

    vector<int> isGood(n, 0);
    for (int i = 0; i < n; i++)
      isGood[i] = check(i);

    int best = 0;
    for (int i = 1; i + 1 < n; i++)
    {
      int tmp = a[i], initial = isGood[i - 1] + isGood[i] + isGood[i + 1];
      a[i] = a[i - 1];
      for (int changeTo = i - 1; changeTo <= i + 1; changeTo += 2)
      {
        a[i] = a[changeTo];
        int newScore = 0;
        for (int j = i - 1; j <= i + 1; j++)
          newScore += check(j);
        best = max(best, initial - newScore);
      }
      a[i] = tmp;
    }

    cout << accumulate(isGood.begin(), isGood.end(), 0) - best << '\n';
  }
}