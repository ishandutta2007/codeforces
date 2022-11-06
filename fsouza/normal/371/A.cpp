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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  int ret = 0;

  for (int i = 0; i < k; i++) {
    vector<int> cnt(3, 0);
    for (int j = i; j < n; j += k)
      cnt[v[j]]++;
    ret += accumulate(cnt.begin(), cnt.end(), 0) - *max_element(cnt.begin(), cnt.end());
  }

  cout << ret << endl;

  return 0;
}