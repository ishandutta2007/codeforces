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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 55
int N;
long long M;

int main(int argc, char *argv[]) {
  vector<int> ans;
  cin >> N >> M;
  ans.push_back(N);
  M--;
  REP(i, N - 1) {
    if (M % 2) ans.push_back(N - i - 1);
    else {
      reverse(ans.begin(), ans.end());
      ans.push_back(N - i - 1);
      reverse(ans.begin(), ans.end());
    }
    M /= 2;
  }
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}