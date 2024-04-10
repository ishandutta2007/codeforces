/* Written by Filip Hlasek 2019 */
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

bool solve(vector<pair <int, int> > a,  vector<pair<int, int> > b) {
  vector< pair<int, int> > event;
  REP(i, (int)a.size()) {
    event.push_back(make_pair(a[i].first, -(i + 1)));
    event.push_back(make_pair(a[i].second, (i + 1)));
  }
  sort(event.begin(), event.end());
  multiset<int> starts, ends;

  REP(i, (int)event.size()) {
    if (event[i].second > 0) {
      int id = event[i].second - 1;
      starts.erase(starts.find(b[id].first));
      ends.erase(ends.find(b[id].second));
    } else {
      int id = (-event[i].second) - 1;
      starts.insert(b[id].first);
      ends.insert(b[id].second);
      multiset<int>::iterator last = starts.end(); --last;
      if (*last > *(ends.begin())) return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  vector< pair<int, int> > a, b;
  REP(i, N) {
    int sa, ea, sb, eb;
    scanf("%d%d%d%d", &sa, &ea, &sb, &eb);
    a.push_back(make_pair(sa, ea));
    b.push_back(make_pair(sb, eb));
  }
  printf("%s\n", solve(a, b) && solve(b, a) ? "YES" : "NO");
	return 0;
}