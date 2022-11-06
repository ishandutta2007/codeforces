#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define MAXS 100000

using namespace std;

typedef long long lint;

char ga[MAXS+1], gb[MAXS+1];

int main() {
  scanf(" %s %s", ga, gb);
  int nga = strlen(ga), ngb = strlen(gb);

  bool ok;

  if (nga != ngb) ok = false;
  else {
    int ng = nga;
    vector< pair<char, char> > diff;

    for (int i = 0; i < ng; i++)
      if (ga[i] != gb[i]) {
	diff.push_back(make_pair(ga[i], gb[i]));
      }

    if (diff.size() == 0) ok = true;
    else if (diff.size() == 2) {
      ok = (diff[0].first == diff[1].second &&
	    diff[1].first == diff[0].second);
    } else ok = false;
  }

  if (ok) printf("YES\n");
  else printf("NO\n");

  return 0;
}