#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m, a[100100];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    int id = n;
    while (id && a[id] == id)
      id--;

    double prob = 1;
    while (m--)
    {
      int r;
      double p;
      cin >> r >> p;
      if (r >= id)
        prob *= 1 - p;
    }

    cout << fixed << setprecision(9) << (id ? 1 - prob : 1) << endl;
  }
}