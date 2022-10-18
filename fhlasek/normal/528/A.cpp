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

class Dimension {
public:
  set< pair<int, int> > by_size, by_start;
  void init(int L) {
    by_size.insert(make_pair(L, 0));
    by_start.insert(make_pair(0, L));
  }
  void cut(int x) {
    set< pair<int, int> >::iterator it = by_start.lower_bound(make_pair(x, 0));
    --it;
    int start = it->first, len = it->second;
    by_start.erase(it);
    by_size.erase(by_size.find(make_pair(len, start)));

    by_start.insert(make_pair(start, x - start));
    by_size.insert(make_pair(x - start, start));

    by_start.insert(make_pair(x, len - (x - start)));
    by_size.insert(make_pair(len - (x - start), x));
  }
  int get_largest() {
    set< pair<int, int> >::iterator it = by_size.end();
    --it;
    return it->first;
  }
};

Dimension x, y;

int main(int argc, char *argv[]) {
  int W, H, N;
  scanf("%d%d%d", &W, &H, &N);
  x.init(W); y.init(H);
  while (N--) {
    char cmd[10];
    int i;
    scanf("%s%d", cmd, &i);
    if (cmd[0] == 'V') x.cut(i);
    else y.cut(i);
    cout << (long long)x.get_largest() * y.get_largest() << endl;
  }
  return 0;
}