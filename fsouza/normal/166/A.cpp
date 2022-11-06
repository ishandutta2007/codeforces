#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n, k;

  scanf("%d %d", &n, &k); k--;

  vector< pair<int, int> > team;

  for (int i = 0; i < n; i++) {
    int p, t;
    scanf("%d %d", &p, &t);
    team.push_back(make_pair(-p, t));
  }

  sort(team.begin(), team.end());

  printf("%d\n", (int)count(team.begin(), team.end(), team[k]));

  return 0;
}