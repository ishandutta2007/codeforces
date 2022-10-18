/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111
int N;
string names[MAXN];
int cmp[MAXN][MAXN];
bool done[MAXN];

queue<int> q;
void add_to_queue() {
  REP(i, 26) if (!done[i]) {
    bool ok = true;
    REP(j, 26) if (!done[j] && cmp[j][i] == 1) { ok = false; break; }
    if (ok) {
      done[i] = true;
      q.push(i);
    }
  }
}

bool solve(int l, int r, int pos) {
  // printf("l: %d r: %d pos: %d\n", l, r, pos);
  if (l == r) return true;
  while (l < r && names[l].size() == pos) l++;
  int start = l;
  FOR(i, l + 1, r - 1) {
    // printf("i: %d start: %d\n", i, start);
    if (names[i].size() <= pos) return false;
    if (names[start][pos] != names[i][pos]) {
      char a = names[start][pos] - 'a', b = names[i][pos] - 'a';
      if (cmp[a][b] == -1) return false;
      cmp[a][b] = 1;
      cmp[b][a] = -1;
      if (!solve(start, i, pos + 1)) return false;
      start = i;
    }
  }
  return solve(start, r, pos + 1);
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) cin >> names[i];
  if (!solve(0, N, 0)) printf("Impossible\n");
  else {
    add_to_queue();
    string ans = "";
    while (!q.empty()) {
      ans.push_back(q.front() + 'a');
      q.pop();
      add_to_queue();
    }
    if (ans.size() == 26) cout << ans << endl;
    else printf("Impossible\n");
  }
  return 0;
}