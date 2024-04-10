#include <bits/stdc++.h>
using namespace std;

int main()
{
  // n <= 22 lol?
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back({x, i});
  }
  sort(begin(a), end(a));

  vector<int> b(n);
  for (int i = 0; i < n; i++)
    b[a[i].second] = a[(i + 1) % n].first;

  for (int x : b)
    cout << x << ' ';
}