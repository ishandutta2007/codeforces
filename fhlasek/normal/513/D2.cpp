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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111
int A[MAXN], B[MAXN];
char Dir[MAXN];
int C;
vector<int> condition_left[MAXN], condition_right[MAXN];
vector<int> left_graph[MAXN], right_graph[MAXN];
int Right[MAXN];
stack<int> s;

bool check() {
  REP(i, C) if (A[i] >= B[i]) return false;
  return true;
}

bool printed = false;
void print_dfs(int n) {
  REP(i, left_graph[n].size()) print_dfs(left_graph[n][i]);
  if (printed) printf(" ");
  printed = true;
  printf("%d", n);
  REP(i, right_graph[n].size()) print_dfs(right_graph[n][i]);
}

bool solve(int N) {
  REP(i, C) {
    if (Dir[i] == 'L') condition_left[A[i]].push_back(B[i]);
    else               condition_right[A[i]].push_back(B[i]);
  }
  FORD(i, N, 1) {
    int CL = condition_left[i].size(), CR = condition_right[i].size();
    int left_last = -1, right_first = MAXN, right_last = -1;
    REP(j, CL) left_last = max(left_last, condition_left[i][j]);
    REP(j, CR) {
      right_first = min(right_first, condition_right[i][j]);
      right_last  = max(right_last , condition_right[i][j]);
    }
    Right[i] = i;
    if (left_last >= right_first) return false;
    while (!s.empty() && s.top() <= left_last) {
      int x = s.top(); s.pop();
      left_graph[i].push_back(x);
      Right[i] = Right[x];
    }
    if (Right[i] >= right_first) return false;
    while (!s.empty() && s.top() <= right_last) {
      int x = s.top(); s.pop();
      right_graph[i].push_back(x);
      Right[i] = Right[x];
    }
    s.push(i);
  }
  while (!s.empty()) {
    int x = s.top(); s.pop();
    print_dfs(x);
  }
  printf("\n");
  return true;
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d%d", &N, &C);
  REP(i, C) {
    char w[10];
    scanf("%d%d%s", A + i, B + i, w);
    Dir[i] = w[0];
  }
  if (!check() || !solve(N)) printf("IMPOSSIBLE\n");
  return 0;
}