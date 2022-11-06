#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
  int n, m;

  cin >> n >> m;

  vector <int> ans(n);
  vector <pair <int, int> > p;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    p.push_back(make_pair(x, i));
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
  }
  
  sort(p.begin(), p.end());

  for (int i = 0; i < n; i++) ans[p[i].second] = i%2;

  for (int i = 0; i < n; i++) {
    if (i-1 >= 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}