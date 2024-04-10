/* Written by Filip Hlasek 2016 */
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

set<string> ans;
#define MAXN 111111
char w[MAXN];
int N;

map<pair<string, int>, bool> dp;
bool finish(string last, int pos) {
  if (pos == N) return true;
  if (pos > N) return false;
  pair<string, int> state = make_pair(last, pos);
  if (dp.count(state)) return dp[state];
  string s;
  s.push_back(w[pos]);
  s.push_back(w[pos + 1]);
  if (last != s && finish(s, pos + 2)) return dp[state] = true;
  s.push_back(w[pos + 2]);
  return dp[state] = last != s && finish(s, pos + 3);
}

int main(int argc, char *argv[]) {
  scanf("%s", w);
  N = strlen(w);
  FOR(i, 5, N - 2) {
    string s;
    s.push_back(w[i]);
    s.push_back(w[i + 1]);
    if (finish(s, i + 2)) ans.insert(s);
    s.push_back(w[i + 2]);
    if (finish(s, i + 3)) ans.insert(s);
  }
  printf("%d\n", (int)ans.size());
  for (set<string>::iterator it = ans.begin(); it != ans.end(); ++it) {
    printf("%s\n", it->c_str());
  }
  return 0;
}