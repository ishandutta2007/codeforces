#include <algorithm>
#include <array>
#include <bitset>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

bool ok;
vector<int> result;
vector<vector<pair<int, int>>> adj;

void dfs(int v, int value) {
  if (result[v] != -1) {
    if (result[v] != value)
      ok = false;
    return;
  }
  result[v] = value;
  for (pair<int, int> udelta : adj[v]) {
    int u, delta;
    tie(u, delta) = udelta;
    dfs(u, (value + delta) % 2);
  }
}

int main() {
  int ndoor, nbutton;
  scanf("%d %d", &ndoor, &nbutton);
  vector<int> state(ndoor);
  for (int i = 0; i < ndoor; ++i)
    scanf("%d", &state[i]);
  vector<vector<int>> controlled_by(ndoor);
  for (int j = 0; j < nbutton; ++j) {
    int ncontrol;
    scanf("%d", &ncontrol);
    for (int rep = 0; rep < ncontrol; ++rep) {
      int i;
      scanf("%d", &i), --i;
      controlled_by[i].push_back(j);
    }
  }

  adj.resize(nbutton);
  for (int i = 0; i < ndoor; ++i) {
    int a, b;
    a = controlled_by[i][0];
    b = controlled_by[i][1];
    adj[a].push_back(make_pair(b, 1 - state[i]));
    adj[b].push_back(make_pair(a, 1 - state[i]));
  }

  ok = true;
  result.resize(nbutton, -1);
  for (int j = 0; j < nbutton; ++j)
    if (result[j] == -1)
      dfs(j, 0);

  if (ok) printf("YES\n");
  else printf("NO\n");

  return 0;
}