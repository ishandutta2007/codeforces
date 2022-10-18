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

vector< pair<int, pair<int, int> > > arrival, departure;
int N, M, K;

#define MAXN 111111
multiset<int> sa[MAXN], sd[MAXN];

#define INF 1000000000000

long long getArrivalCost(int city) {
  if (sa[city].empty()) return INF;
  return *sa[city].begin();
}

long long getDepartureCost(int city) {
  if (sd[city].empty()) return INF;
  return *sd[city].begin();
}

int main(int argc, char *argv[]) {

  scanf("%d%d%d", &N, &M, &K);
  while (M--) {
    int d, f, t, c;
    scanf("%d%d%d%d", &d, &f, &t, &c);
    if (t == 0) {
      arrival.push_back(make_pair(d, make_pair(f, c)));
    } else {
      departure.push_back(make_pair(d, make_pair(t, c)));
      sd[t].insert(c);
    }
  }
  sort(arrival.begin(), arrival.end());
  sort(departure.begin(), departure.end());
  // REP(i, departure.size()) printf(" %d", departure[i].second.second); printf("\n");

  long long cur = 0;
  REP(i, N) cur += getArrivalCost(i + 1) + getDepartureCost(i + 1);
  long long best = cur;

  int j = 0;

  REP(i, arrival.size()) {
    int day = arrival[i].first, city = arrival[i].second.first, cost = arrival[i].second.second;
    cur -= getArrivalCost(city);
    sa[city].insert(cost);
    cur += getArrivalCost(city);
    while (j < (int)departure.size() && departure[j].first <= day + K) {
      int dcity = departure[j].second.first, dcost = departure[j].second.second;
      cur -= getDepartureCost(dcity);
      sd[dcity].erase(sd[dcity].find(dcost));
      cur += getDepartureCost(dcity);
      j++;
    }
    best = min(best, cur);
  }

  if (best >= INF) {
    cout << -1 << endl;
  } else {
    cout << best << endl;
  }

  return 0;
}