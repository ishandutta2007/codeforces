/* Written by Filip Hlasek 2017 */
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

#define MAXN 1111
string A[MAXN], B[MAXN];
int N;
string ans[MAXN];
bool ok = true;

vector<int> m[33][33];

void solve(vector<int> &teams) {
  int T = teams.size();
  if (T > 26) { ok = false; return; }
  bool taken[33];
  REP(i, 26) taken[i] = false;
  bool a[33];
  REP(i, T) a[i] = false;
  queue<int> q;
  REP(i, T) REP(j, T) if (j != i && A[teams[i]][2] == A[teams[j]][2]) {
    q.push(teams[i]);
    a[i] = true;
    break;
  }
  REP(i, T) {
    int t = teams[i];
    ans[t].push_back(A[t][0]);
    ans[t].push_back(A[t][1]);
  }
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    if (taken[B[t][0] - 'A']) { ok = false; return; }
    ans[t].push_back(B[t][0]);
    taken[B[t][0] - 'A'] = true;
    REP(i, T) if (!a[i] && A[teams[i]][2] == B[t][0]) {
      q.push(teams[i]);
      a[i] = true;
      break;
    }
  }
  REP(i, T) if (!a[i]) {
    int t = teams[i];
    ans[t].push_back(A[t][2]);
  }
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) {
    cin >> A[i] >> B[i];
    m[A[i][0] - 'A'][A[i][1] - 'A'].push_back(i);
  }
  REP(i, 33) REP(j, 33) solve(m[i][j]);
  if (ok) {
    printf("YES\n");
    REP(i, N) printf("%s\n", ans[i].c_str());
  } else {
    printf("NO\n");
  }
  return 0;
}