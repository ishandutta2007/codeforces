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
  int n, m, k;

  cin >> n >> m >> k;

  vector <pair <int, int> > seq;

  for (int y = 0; y < n; y++) {
    if (y%2 == 0) {
      for (int x = 0; x < m; x++) seq.push_back(make_pair(y, x));
    } else {
      for (int x = m-1; x >= 0; x--) seq.push_back(make_pair(y, x));
    }
  }
  
  vector <int> sizes(k, 2);
  sizes[k-1] = n * m - 2 * (k-1);

  int pos = 0;
  for (int i = 0; i < k; i++) {
    cout << sizes[i];
    for (int j = 0; j < sizes[i]; j++) {
      cout << " " << seq[pos].first+1 << " " << seq[pos].second+1;
      pos++;
    }
    cout << endl;
  }

  return 0;
}