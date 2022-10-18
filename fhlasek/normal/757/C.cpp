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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MOD 1000000007
#define MAXN 1111111
int N, M;
int group[MAXN];

int cnt[MAXN], done[MAXN];
vector<int> gym;
map<long long, int> mmm;
int MMM = 1;

map<int, int> group_cnt;

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) {
    int G;
    scanf("%d", &G);
    gym.clear();
    REP(j, G) {
      int m;
      scanf("%d", &m); m--;
      if (done[m] != i + 1) {
        cnt[m] = 0;
        gym.push_back(m);
      }
      done[m] = i + 1;
      cnt[m]++;
    }
    REP(j, gym.size()) {
      int m = gym[j];
      int c = cnt[m];
      long long status = group[m];
      status = MAXN * status + c;
      status = MAXN * status + i;
      if (mmm.count(status)) group[m] = mmm[status];
      else group[m] = (mmm[status] = MMM++);
    }

  }
  REP(i, M) group_cnt[group[i]]++;
  long long ans = 1;
  for (map<int, int>::iterator it = group_cnt.begin(); it != group_cnt.end(); ++it) {
    REP(i, it->second) ans = (ans * (i + 1)) % MOD;
  }
  printf("%d\n", (int)ans);
  return 0;
}