/* Written by Filip Hlasek 2018 */
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

#define MAXN 3333
vector<int> voters[MAXN];

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i, N) {
    int P, C;
    scanf("%d%d", &P, &C);
    voters[P - 1].push_back(C);
  }
  REP(i, M) sort(voters[i].begin(), voters[i].end());
  long long ans = N * 1000000000LL;
  FOR(win, 1, N) {
    vector<int> other;
    long long tmp = 0;
    int have = voters[0].size();
    FOR(party, 1, M - 1) {
      int take = max(0, (int)voters[party].size() - (win - 1));
      REP(i, take) tmp += voters[party][i];
      have += take;
      FOR(i, take, (int)voters[party].size() - 1) other.push_back(voters[party][i]);
    }
    sort(other.begin(), other.end());
    int take = max(0, win - have);
    REP(i, take) tmp += other[i];
    ans = min(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}