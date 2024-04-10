#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define INF 1000000000

using namespace std;

int main() {
  int n;

  scanf("%d", &n);

  vector<int> pos[2];
  vector<int> link[2];

  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    pos[v-1].push_back(i);
    link[v-1].push_back(pos[(v-1)^1].size());
  }

  vector <pair <int, int> > ans;

  for (int t = 1; t <= n; t++) {
    int nseta = 0, nsetb = 0;
    int a = 0, b = 0;
    bool ok = true;

    int last = -1;

    while (a < (int)pos[0].size() || b < (int)pos[1].size()) {
      int woulda = (a+t <= (int)pos[0].size()) ? pos[0][a+t-1] : INF;
      int wouldb = (b+t <= (int)pos[1].size()) ? pos[1][b+t-1] : INF;
      
      if (woulda == INF && wouldb == INF) {
	ok = false;
	break;
      }

      if (woulda < wouldb) {
	nseta++;
	b = link[0][a+t-1];
	a += t;
	last = 0;
      } else {
	nsetb++;
	a = link[1][b+t-1];
	b += t;
	last = 1;
      }
    }
    
    if (last == 0) ok &= (nseta > nsetb);
    if (last == 1) ok &= (nsetb > nseta);

    if (nseta == nsetb)
      ok = false;

    if (ok)
      ans.push_back(make_pair(max(nseta, nsetb), t));
  }
  
  sort(ans.begin(), ans.end());

  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);

  return 0;
}