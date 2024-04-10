#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <utility>
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

struct data {
  set <pair <int, int> > caneat; // m, id
  set <pair <int, pair <int, int> > > others; // h, m, id

  void add(int h, int m, int i) {
    others.insert(make_pair(h, make_pair(m, i)));
  }

  void update(int st) {
    while (!others.empty() && others.begin() -> first <= st) {
      caneat.insert(others.begin() -> second);
      others.erase(others.begin());
    }
  }
};

int solve(data a, data b, int st) {
  int ret = 0;
  while (1) {

    {
    a.update(st);
    if (a.caneat.empty()) break;
    pair <int, int> eat = *a.caneat.rbegin();
    st += eat.first;
    a.caneat.erase(eat);
    ret++;
    }

    {
    b.update(st);
    if (b.caneat.empty()) break;
    pair <int, int> eat = *b.caneat.rbegin();
    st += eat.first;
    b.caneat.erase(eat);
    ret++;    
    }
  }
  return ret;
}

int main(int argc, char ** argv)
{
  int n, x;
  data d[2];

  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    int t, h, m;
    cin >> t >> h >> m;
    d[t].add(h, m, i);
  }

  cout << max(solve(d[0], d[1], x), solve(d[1], d[0], x)) << endl;

  return 0;
}