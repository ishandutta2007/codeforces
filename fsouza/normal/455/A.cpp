#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 100000

using namespace std;

typedef long long lint;

lint dp[MAXN+1][2];

int main() {
  map <int, int> manymap;
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      manymap[v]++;
    }
  }

  vector< pair<int, int> > ac(manymap.begin(), manymap.end());
  int n = ac.size();

  dp[n][0] = dp[n][1] = 0;
  for (int i = n-1; i >= 0; i--) {
    dp[i][0] = max((lint)ac[i].first * ac[i].second + dp[i+1][1], dp[i+1][0]);
    if (i-1 >= 0) {
      if (ac[i].first == ac[i-1].first+1)
	dp[i][1] = dp[i+1][0];
      else
	dp[i][1] = dp[i][0];
    }
  }

  cout << dp[0][0] << endl;
  
  return 0;
}