/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 222222
set<int> ans;

int N, M;
vector<int> word[MAXN];
vector<int> graph[MAXN];

int getLetter(int i, int j) {
  if ((int)word[i].size() <= j) return 0;
  return word[i][j];
}

void solve() {
  REP(i, N - 1) {
    REP(j, max(word[i].size(), word[i + 1].size())) {
      int l1 = getLetter(i, j), l2 = getLetter(i + 1, j);
      if (l1 < l2) { if (l1) graph[l2].push_back(l1); break; }
      if (l1 > l2) { ans.insert(l1); break; }
    }
  }
}

int getLetter2(int i, int j) {
  int l = getLetter(i, j);
  if (!l) return 0;
  return ans.find(l) != ans.end() ? l : l + M;
}

bool verify() {
  REP(i, N - 1) {
    REP(j, max(word[i].size(), word[i + 1].size())) {
      int l1 = getLetter2(i, j), l2 = getLetter2(i + 1, j);
      if (l1 < l2) break;
      if (l1 > l2) return false;
    }
  }
  return true;
}

void dfs(int v) {
  REP(i, graph[v].size()) if (ans.find(graph[v][i]) == ans.end()) {
    ans.insert(graph[v][i]);
    dfs(graph[v][i]);
  }
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) {
    int l;
    scanf("%d", &l);
    REP(j, l) {
      int a;
      scanf("%d", &a);
      word[i].push_back(a);
    }
  }
  solve();
  FOR(i, 1, M) if (ans.find(i) != ans.end()) dfs(i);
  if (verify()) {
    printf("Yes\n");
    vector<int>a(ans.begin(), ans.end());
    printf("%d\n", (int)a.size());
    REP(i, a.size()) {
      if (i) printf(" ");
      printf("%d", a[i]);
    }
    printf("\n");
  } else {
    printf("No\n");
  }
  return 0;
}