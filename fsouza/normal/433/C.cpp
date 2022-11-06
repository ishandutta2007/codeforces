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
#define MAXN 100000
#define MAXM 100000

typedef long long lint;

using namespace std;

int seq[MAXM];
vector <int> adj[MAXN];

int main(int argc, char ** argv)
{
  int n, m;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) scanf("%d", &seq[i]), seq[i]--;

  for (int i = 0; i+1 < m; i++) {
    if (seq[i] != seq[i+1]) {
      adj[seq[i]].push_back(seq[i+1]);
      adj[seq[i+1]].push_back(seq[i]);
    }
  }

  lint result = 0;
  lint bestdel = 0;

  for (int i = 0; i < n; i++)
    if (!adj[i].empty()) {
      lint res0 = 0, res1 = 0;

      nth_element(adj[i].begin(), adj[i].begin() + adj[i].size()/2, adj[i].end());
      int mid = adj[i][adj[i].size()/2];

      for (int j = 0; j < (int)adj[i].size(); j++) res0 += abs(i - adj[i][j]);
      for (int j = 0; j < (int)adj[i].size(); j++) res1 += abs(mid - adj[i][j]);

      result += res0;
      bestdel = max(bestdel, res0 - res1);
    }

  cout << result/2 - bestdel << endl;

  return 0;
}