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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 222222
int N;
int _right[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", _right + i);
  int _left = 0;
  REP(i, N) _left += 1 - _right[i];
  long long ans = 0;
  REP(i, N) {
    if (_right[i]) ans += _left;
    else _left--;
  }

  cout << ans << endl;
  return 0;
}