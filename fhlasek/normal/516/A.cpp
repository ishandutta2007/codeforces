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

char input[111];
int N;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  scanf("%s", input);
  vector<int> ans;
  REP(ii, N) {
    int i = input[ii] - '0';
    if (i < 2) continue;
    if (i == 4) { ans.push_back(3); ans.push_back(2); ans.push_back(2); }
    else if (i == 6) { ans.push_back(5); ans.push_back(3); }
    else if (i == 8) { ans.push_back(7); ans.push_back(2); ans.push_back(2); ans.push_back(2); }
    else if (i == 9) { ans.push_back(7); ans.push_back(3); ans.push_back(3); ans.push_back(2); }
    else ans.push_back(i);
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  REP(i, ans.size()) printf("%d", ans[i]); printf("\n");
  return 0;
}