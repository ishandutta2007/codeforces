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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> y, x;
  int lasty = 0, lastx = 0;

  y.push_back(lasty); x.push_back(lastx);
  for (int i = 0; i < n; i++) {
    lastx += a[i];
    if (i%2 == 0) lasty += a[i];
    else lasty -= a[i];
    y.push_back(lasty); x.push_back(lastx);
  }

  int miny = *min_element(y.begin(), y.end()), maxy = *max_element(y.begin(), y.end());
  int height = maxy - miny, width = x.back();
  vector <string> field(height, string(width, ' '));

  for (int i = 0; i < n; i++) {
    int yy = y[i];
    for (int xx = x[i]; xx < x[i+1]; xx++) {
      if (yy < y[i+1]) {
	field[yy - miny][xx] = '/';
	yy++;
      } else {
	yy--;
	field[yy - miny][xx] = '\\';
      }
    }
  }

  reverse(field.begin(), field.end());
  for (int i = 0; i < (int)field.size(); i++) cout << field[i] << endl;

  return 0;
}