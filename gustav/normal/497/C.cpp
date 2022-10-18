#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

enum { ACTOR, PART };

struct Event {
  int x, y;
  int k;
  int type;
  int id;

  Event(int x, int y, int k, int type, int id) :
    x(x), y(y), k(k), type(type), id(id) {}
};

vector< Event > E;

bool operator<(const Event &a, const Event &b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.type != b.type) return a.type < b.type;
  return a.y < b.y;
}

const int MAX = 100005;

int n, m;
int a[MAX], b[MAX];
int c[MAX], d[MAX], k[MAX];
int sol[MAX];

struct cmp {
  bool operator()(int i, int j) {
    if (d[i] != d[j]) return d[i] < d[j];
    return i > j;
  }
};

set< int, cmp > M;


int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d%d", a + i, b + i);

  scanf("%d", &m);
  REP(i, m) scanf("%d%d%d", c + i, d + i, k + i);

  REP(i, n)
    E.push_back(Event(a[i], b[i], 0, PART, i));

  REP(i, m)
    E.push_back(Event(c[i], d[i], k[i], ACTOR, i));

  sort(E.begin(), E.end());

  for (Event &e : E) {
    if (e.type == ACTOR) {
      M.insert(e.id);
    } else {
      d[m] = e.y;
      auto lb = M.lower_bound(m); 

      if (lb == M.end()) {
        puts("NO");
        exit(0);
      }
  
      int id = *lb;
      sol[e.id] = id + 1;

      if (--k[id] == 0) 
        M.erase(id);
    }
  }

  puts("YES");

  REP(i, n) printf("%d ", sol[i]);
  puts("");

  return 0;
}