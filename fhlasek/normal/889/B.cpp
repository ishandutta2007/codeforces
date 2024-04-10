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

#define MAXN 111111
string w[MAXN];
int W;

int occur[33];
int Next[33];

string ans;

int main(int argc, char *argv[]) {
  cin >> W;
  REP(i, W) cin >> w[i];
  REP(i, W) if ((int)w[i].size() > 26) {
    printf("NO\n");
    return 0;
  }
  REP(i, W) REP(j, (int)w[i].size()) {
    occur[w[i][j] - 'a'] = true;
    if (j + 1 < (int)w[i].size()) {
      Next[w[i][j] - 'a'] = w[i][j + 1] - 'a' + 1;
    }
  }
  REP(i, 26) if (occur[i]) {

    bool valid = true;
    REP(j, 26) if (occur[j] && Next[j] - 1 == i) { valid = false; break; }
    if (!valid) continue;

    int j = i;
    while (occur[j]) {
      ans.push_back(j + 'a');
      occur[j] = false;
      if (Next[j] == 0) break;
      j = Next[j] - 1;
    }
  }
  REP(i, W) if (ans.find(w[i]) == string::npos) {
    printf("NO\n");
    return 0;
  }
  printf("%s\n", ans.c_str());
   
  return 0;
}