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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; ++i) cin >> strs[i];
  set<string> mark;
  for (int i = n-1; i >= 0; --i)
    if (mark.insert(strs[i]).second)
      cout << strs[i] << endl;

  return 0;
}