/* Written by Filip Hlasek 2014 */
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

#define MAXN 1111
int N, P;
char input[MAXN];

map<pair<pair<int, bool>, pair<char, char> >, string> dp;

string possible(int n, char l1 = 0, char l2 = 0, bool bigger = true) {
  if (n == 0) {
    if (bigger) return "-1";
    return "";
  }

  pair<pair<int, bool>, pair<char, char> > s = make_pair(make_pair(n, bigger), make_pair(l1, l2));
  if (dp.count(s)) return dp[s];

  if (bigger) {
    int ch = input[N - n];
    if (ch != l1 || ch != l2) {
      string tmp = possible(n - 1, l2, ch, true);
      if (tmp != "-1") {
        tmp.push_back(ch);
        return dp[s] = tmp;
      }
    }
    FOR(i, ch + 1, P + 'a' - 1) {
      if (i == l1 || i == l2) continue;
      string tmp = possible(n - 1, l2, i, false);
      if (tmp != "-1") {
        tmp.push_back(i);
        return dp[s] = tmp;
      }
    }
  }
  else {
    REP(i, P) {
      if (i + 'a' == l1 || i + 'a' == l2) continue;
      string tmp = possible(n - 1, l2, i + 'a', false);
      if (tmp != "-1") {
        tmp.push_back(i + 'a');
        return dp[s] = tmp;
      }
    }
  }
  return dp[s] = "-1";
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &P);
  scanf("%s", input);
  string ans = possible(N);
  if (ans == "-1") printf("NO\n");
  else {
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
  }
  return 0;
}