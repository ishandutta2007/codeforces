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

set<int> s;

int main(int argc, char *argv[]) {
  s.insert(0);
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) {
    int a;
    scanf("%d", &a);
    if (s.find(a) != s.end()) s.erase(s.find(a));
    s.insert(i);
  }
  printf("%d\n", (int)s.size());
  return 0;
}