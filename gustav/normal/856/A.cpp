#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 1e6 + 1;
int deltas[MAX];

void solve() {
  int N;
  cin >> N;

  vector<int> v;
  REP(i, N) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  REP(i, N) FOR(j, i + 1, N)
    deltas[abs(v[i] - v[j])] = 1;

  vector<int> sol;
  sol.reserve(N);
  
  for (int i = 1; i < MAX && sol.size() < N; ++i) {
    bool ok = true;
    REP(j, (int)sol.size()) {
      if (deltas[abs(i - sol[j])]) {
	ok = false;
	break;
      }
    }
    if (ok)
      sol.push_back(i);
  }

  REP(i, N) FOR(j, i + 1, N)
    deltas[abs(v[i] - v[j])] = 0;

  if (sol.size() == N) {
    puts("YES");
    REP(i, N) 
      printf("%d%c", sol[i], " \n"[i + 1 == N]);
  } else {
    puts("NO");
  }
}

int main(void) 
{
  int T;
  cin >> T;
  while (T--) solve();

  return 0;
}