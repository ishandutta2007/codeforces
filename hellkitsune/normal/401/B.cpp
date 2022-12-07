#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

pair<int, int> r[4005];
int n, m;

int main()
{
  cin >> n >> m;
  int x, y, dum;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    if (x == 1)
      cin >> dum;
    r[i] = make_pair(y, x);
  }
  r[m] = make_pair(0, 2);
  r[m + 1] = make_pair(n, 2);
  sort(r, r + (m + 2));
  int min2 = 0, max2 = 0;
  for (int i = 1; i <= m + 1; ++i) {
    int am = r[i].first - r[i - 1].first - 1;
    if (r[i - 1].second == 1)
      --am;
    min2 += am / 2 + am % 2;
    max2 += am;
  }
  cout << min2 << ' ' << max2 << endl;
  return 0;
}