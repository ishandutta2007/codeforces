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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

map<int, int> mx, my;
map<pair<int, int>, int> m;

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    int x, y;
    scanf("%d%d", &x, &y);
    mx[x]++;
    my[y]++;
    m[make_pair(x, y)]++;
  }
  long long ans = 0;
  for (map<int, int>::iterator it = mx.begin(); it != mx.end(); ++it) {
    ans += ((long long)it->second * (it->second - 1)) / 2;
  }
  for (map<int, int>::iterator it = my.begin(); it != my.end(); ++it) {
    ans += ((long long)it->second * (it->second - 1)) / 2;
  }
  for (map<pair<int, int>, int>::iterator it = m.begin(); it != m.end(); ++it) {
    ans -= ((long long)it->second * (it->second - 1)) / 2;
  }
  cout << ans << endl;
  return 0;
}