#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>

typedef long long lint;

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  int x2, y2;
  cin >> x2 >> y2;

  int x = 0, y = 0, d = 0;
  int dist = 0, ret = 0;
  set <pair <int, int> > vis;

  while (x != x2 || y != y2) {
    vis.insert(make_pair(x, y));
    if (dist > 0) {
      int d2 = (d-1+4)%4;
      if (vis.find(make_pair(x + dx[d2], y + dy[d2])) == vis.end()) {
        d = d2;
        ret++;
      }
    }
    x += dx[d], y += dy[d];
    dist++;
  }

  cout << ret << endl;

  return 0;
}