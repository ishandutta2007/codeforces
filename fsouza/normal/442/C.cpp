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

vector<pair <int, int> > vv;
void eat(int bl, int br, vector<int> &a, vector<int> &next, vector<int> &prev, lint &result) {
  vv.clear();
  for (int id = next[bl]; id != br; id = next[id]) {
    vv.push_back(make_pair(a[id], id));
  }
  sort(vv.begin(), vv.end());
  for (int i = 0; i < (int)vv.size(); i++) {
    int id = vv[i].second;
    result += min(a[prev[id]], a[next[id]]);
    next[prev[id]] = next[id];
    prev[next[id]] = prev[id];
  }
}

int main(int argc, char ** argv)
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair <int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end());

  vector<int> next(n+1), prev(n+1);

  for (int i = 0; i < n; i++) next[i] = i+1, prev[i] = i-1;
  prev[0] = next[n-1] = n;
  next[n] = 0, prev[n] = n-1;

  int bl = v.back().second, br = v.back().second;
  lint result = 0;

  for (int i = n-2; i >= 0; i--) {
    int val = v[i].first, id = v[i].second;
    if (bl <= id && id <= br) continue;
    bl = min(bl, id);
    br = max(br, id);
    eat(bl, br, a, next, prev, result);
  }

  cout << result << endl;

  return 0;
}