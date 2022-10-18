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

int Wait[] = { 3, 4, 5, 2, 1, 0 };

int main(int argc, char *argv[]) {
  long long l;
  char seat;
  cin >> l >> seat;
  l--;
  long long ans = (l / 4) * 16 + (l % 2) * 7;
  cout << ans + Wait[seat - 'a'] + 1 << endl;
  return 0;
}