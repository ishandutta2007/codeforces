#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<lint> point;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

struct shooter {
  point origin;
  map<pair<int, int>, vector<pair<lint, int>>> halfline;
  shooter(point origin): origin(origin) {}
  void precalc(vector<point> &targets) {
    for (int i = 0; i < (int)targets.size(); ++i) {
      point dir = targets[i] - origin;
      lint dist2 = norm(dir);
      dir /= gcd(abs(dir.imag()), abs(dir.real()));
      pair<int, int> dir2 = make_pair(dir.real(), dir.imag());
      halfline[dir2].push_back(make_pair(dist2, i));
    }
    for (auto &it : halfline)
      sort(it.second.begin(), it.second.end());
  }
  void underfire(point target, int limit, vector<int> &result) {
    point dir = target - origin;
    lint dist2 = norm(dir);
    dir /= gcd(abs(dir.imag()), abs(dir.real()));
    pair<int, int> dir2 = make_pair(dir.real(), dir.imag());
    vector<pair<lint, int>> &people = halfline[dir2];
    result.clear();
    for (int i = 0; i < (int)people.size() && (int)result.size() < limit && people[i].first < dist2; ++i)
      result.push_back(people[i].second);
  }
};

vector<shooter> shooters;
vector<point> targets;

bool brute(int can, vector<int> tokill) {
  const int many = __builtin_popcount(can);
  if (tokill.empty()) return true;
  if ((int)tokill.size() > many) return false;

  vector<int> middle;
  for (int i = 0; i < (int)shooters.size(); ++i) {
    if (!(can & (1<<i))) continue;
    for (int monster : tokill) {
      shooters[i].underfire(targets[monster], many, middle);
      if ((int)middle.size() < many) {
	vector<int> tokill2 = tokill;
	tokill2.insert(tokill2.end(), middle.begin(), middle.end());
	sort(tokill2.begin(), tokill2.end());
	tokill2.resize(unique(tokill2.begin(), tokill2.end())-tokill2.begin());
	for (int j = (int)tokill2.size()-1; j >= 0; --j)
	  if (tokill2[j] == monster) {
	    tokill2[j] = tokill2.back();
	    tokill2.pop_back();
	  }

	if (brute(can ^ (1<<i), tokill2))
	  return true;
      }
    }
  }

  return false;
}

int main() {
  int k, n;
  scanf("%d %d", &k, &n);

  for (int i = 0; i < k; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    shooters.push_back(shooter(point(x, y)));
  }
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    targets.push_back(point(x, y));
  }
  for (int i = 0; i < k; ++i) {
    shooters[i].precalc(targets);
  }

  int result = 0;

  for (int i = 0; i < n; ++i)
    if (brute((1<<k)-1, {i}))
      ++result;

  printf("%d\n", result);

  return 0;
}