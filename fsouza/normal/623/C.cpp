#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;
const lint big = 1000000000000000000LL;

lint p2(lint x) { return x * x; }

bool possible(int n, const vector<pair<int, int>> &points, lint maxdist2) {
  vector<lint> leftmin(n), leftmax(n), rightmin(n), rightmax(n);

  rightmin[n-1] = rightmax[n-1] = points[n-1].second;
  for (int i = n-2; i >= 0; --i) {
    rightmin[i] = min(rightmin[i+1], (lint)points[i].second);
    rightmax[i] = max(rightmax[i+1], (lint)points[i].second);
  }

  leftmin[0] = leftmax[0] = points[0].second;
  for (int i = 1; i < n; ++i) {
    leftmin[i] = min(leftmin[i-1], (lint)points[i].second);
    leftmax[i] = max(leftmax[i-1], (lint)points[i].second);
  }

  int j = -1;
  for (int i = 0; i < n; ++i) {
    lint maxx = points[i].first;

    while (j+1 < i && p2(points[i].first - points[j+1].first) > maxdist2)
      ++j;
    lint minx = points[j+1].first;
    lint absx = max(abs(minx), abs(maxx));

    int end = i;
    int start = j+1;
    
    if (end-start+1 == n) {
      lint res = p2(maxx-minx);
      if (res <= maxdist2) return true;
    } else {
      lint maxy = -big, miny = +big;
      if (end+1 < n) {
	maxy = max(maxy, rightmax[end+1]);
	miny = min(miny, rightmin[end+1]);
      }
      if (start-1 >= 0) {
	maxy = max(maxy, leftmax[start-1]);
	miny = min(miny, leftmin[start-1]);
      }
      
      lint absy = max(abs(miny), abs(maxy));

      lint res = max({p2(maxx-minx), p2(maxy-miny), absx*absx + absy*absy});
      if (res <= maxdist2) return true;
    }
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = make_pair(x, y);
  }
  sort(points.begin(), points.end());

  vector<pair<int, int>> invpoints(n);
  for (int i = 0; i < n; ++i) {
    invpoints[i] = points[i];
    swap(invpoints[i].first, invpoints[i].second);
  }
  sort(invpoints.begin(), invpoints.end());

  lint l = 0, r = 1000000000000000000LL;
  while (l < r) {
    lint m = (l+r)/2;
    if (possible(n, points, m) || possible(n, invpoints, m)) r = m;
    else l = m+1;
  }

  cout << l << endl;
  
  return 0;
}