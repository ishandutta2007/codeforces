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
  int n;
  scanf("%d", &n);
  vector<string> table(n, string(n, ' '));
  for (string &line : table) scanf("%s", &line[0]);
  vector<int> guess(n), score(n, 0);
  for (int &v : guess) scanf("%d", &v);
  vector<bool> inoutput(n, false);
  queue<int> q;
  for (int i = 0; i < n; ++i)
    if (score[i] == guess[i]) {
      q.push(i);
      inoutput[i] = true;
    }
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u = 0; u < n; ++u)
      if (table[v][u] == '1') {
	++score[u];
	if (score[u] >= guess[u] && !inoutput[u]) {
	  q.push(u);
	  inoutput[u] = true;
	}
      }
  }
  vector<int> output;
  for (int i = 0; i < n; ++i)
    if (inoutput[i])
      output.push_back(i);
  printf("%d\n", (int)output.size());
  for (int i = 0; i < (int)output.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", output[i]+1);
  }
  printf("\n");

  return 0;
}