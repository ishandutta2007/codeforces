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
  int cnt[5] = {0};

  cin >> n;

  bool ok = true;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    v /= 25;
    cnt[v]++;
    int change = v-1;
    for (int k = change; k >= 1; k--)
      while (change >= k && cnt[k] > 0) {
	cnt[k]--;
	change -= k;
      }
    if (change) ok = false;
  }

  if (!ok) cout << "NO" << endl;
  else cout << "YES" << endl;

  return 0;
}