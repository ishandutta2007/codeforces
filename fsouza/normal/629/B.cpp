#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  struct person {
    char gender;
    int start, end;
  };
  vector<person> people(n);
  for (int i = 0; i < n; ++i)
    scanf(" %c %d %d", &people[i].gender, &people[i].start, &people[i].end);

  struct event {
    bool add;
    int when;
    char gender;
  };
  vector<event> events;
  for (int i = 0; i < n; ++i) {
    events.push_back({true, people[i].start, people[i].gender});
    events.push_back({false, people[i].end+1, people[i].gender});
  }
  sort(events.begin(), events.end(), [](const event &a, const event &b) {
      return a.when < b.when;
    });

  int result = 0;
  int nm = 0, nf = 0;
  for (int j = 0, i = j; i < (int)events.size(); i = j) {
    while (j < (int)events.size() && events[j].when == events[i].when) ++j;
    for (int k = i; k < j; ++k) {
      event &ev = events[k];
      int &many = ev.gender == 'M' ? nm : nf;
      if (ev.add) ++many;
      else --many;
    }
    result = max(result, 2*min(nm, nf));
  }

  printf("%d\n", result);
  
  return 0;
}