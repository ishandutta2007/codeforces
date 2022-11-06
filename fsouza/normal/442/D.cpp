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
#define MAXN 1000010

typedef long long lint;

using namespace std;

const int maxans = 25;

vector<int> child[MAXN];
int need[MAXN][maxans+1];
int mi[3];

void solve(int v) {
  for (int i = 0; i < (int)child[v].size(); i++) solve(child[v][i]);

  need[v][0] = v;
  need[v][1] = v;
  for (int ans = 2; ans <= maxans; ans++) {
    need[v][ans] = INF;
  }

  for (int ans = 0; ans <= maxans; ans++) {
    for (int k = 0; k < 3; k++) mi[k] = INF;

    for (int i = 0; i < (int)child[v].size(); i++) {
      mi[2] = need[child[v][i]][ans];
      if (mi[2] < mi[1]) {
	swap(mi[2], mi[1]);
	if (mi[1] < mi[0])
	  swap(mi[1], mi[0]);
      }
    }

    need[v][ans] = min(need[v][ans], mi[0]);

    if (ans + 1 <= maxans && v)
      need[v][ans+1] = min(need[v][ans+1], mi[1]);
  }
}

int main(int argc, char ** argv)
{
  int n;

  cin >> n;
  n++;

  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    child[p].push_back(i);
  }

  solve(0);

  for (int i = 1; i < n; i++) {
    if (i-1 >= 1) cout << " ";
    int ans = 0;
    while (ans+1 <= maxans && need[0][ans+1] <= i) ans++;
    cout << ans;
  }
  cout << endl;

  return 0;
}