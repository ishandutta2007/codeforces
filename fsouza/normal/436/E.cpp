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
#define INFLL (1000000000000000000LL)

typedef long long lint;

using namespace std;

struct guy {
  int cost[3], many, cost2, i;
  guy(int a, int b, int many, int cost2, int i): many(many), cost2(cost2), i(i) {
    cost[0] = 0, cost[1] = a, cost[2] = b;
  }
  bool operator < (const guy &other) const {return cost2 < other.cost2;}
};

int main(int argc, char ** argv)
{
  int n, w;
  vector<guy> guys;

  cin >> n >> w;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (b-a < a) {
      guys.push_back(guy(a, b, 2, b, i));
    } else {
      guys.push_back(guy(a, -1, 1, 2*a, i));
      int d = b-a;
      guys.push_back(guy(d, -1, 1, 2*d, i));
    }
  }

  sort(guys.begin(), guys.end());
  int ng = guys.size();

  const int maxskip = 4;

  vector <vector<lint> > dp(ng+1, vector<lint>(maxskip+1, INFLL));
  dp[0][0] = 0;

  for (int g = 0; g < ng; g++)
    for (int oldskip = 0; oldskip <= maxskip; oldskip++)
      for (int put = 0; put <= guys[g].many; put++) {
	const int newskip = oldskip + (guys[g].many - put);
	if (newskip > maxskip) continue;
	dp[g+1][newskip] = min(dp[g+1][newskip], dp[g][oldskip] + guys[g].cost[put]);
      }

  pair <lint, pair <int, int> > best = make_pair(INFLL, make_pair(-1, -1));

  int manysum = 0;
  for (int g = 0; g < ng; g++) {
    manysum += guys[g].many;
    for (int skip = 0; skip <= maxskip; skip++)
      if (manysum - skip == w)
	best = min(best, make_pair(dp[g+1][skip], make_pair(g, skip)));
  }

  vector<int> ans(n, 0);

  {
    int g = best.second.first, skip = best.second.second;
    while (g >= 0) {
      for (int oldskip = 0; oldskip <= maxskip; oldskip++)
	for (int put = 0; put <= guys[g].many; put++) {
	  const int newskip = oldskip + (guys[g].many - put);
	  if (newskip == skip && dp[g+1][newskip] == dp[g][oldskip] + guys[g].cost[put]) {
	    ans[guys[g].i] += put;
	    skip = oldskip;
	    g--;
	    goto next;
	  }
	}
    next:
      ;
    }
  }

  cout << best.first << endl;
  for (int i = 0; i < n; i++) cout << ans[i];
  cout << endl;

  return 0;
}