#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <unordered_set>
#include <map>
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

#define MAX 50005
#define MAXQ 100005

string s;
int Q;
string s1[MAXQ], s2[MAXQ];

map< string, int > idx;
int cidx;

int get_idx(string &s) {
  if (idx.count(s) == 0) return -1;
  return idx[s];
}

set< pair< int, int > > qq;
pair< int, int > qs[MAXQ];
map< pair< int, int >, int > sol;

vector< int > positions[8 * MAX];
set< int > queries[8 * MAX];
int len[8 * MAX];

struct cmp {
  llint val(int x) { 
    return (llint)positions[x].size() * queries[x].size(); 
  }
  bool operator()(int a, int b) { 
    if (val(a) == val(b)) return a < b;
    return val(a) < val(b);
  }
};

set< int, cmp > pq;

int main(void)
{
  cin >> s;

  REP(i, s.size()) {
    for (int j = 1; j <= 4 && i + j <= s.size(); ++j) {
      int id;
      string z = s.substr(i, j);
      if (idx.count(z) == 0) {
        id = idx[z] = cidx++;
      } else {
        id = idx[z];
      }
      len[id] = j;
      positions[id].push_back(i);
    }
  }

  cin >> Q;

  REP(i, Q) {
    cin >> s1[i] >> s2[i];
    int x = get_idx(s1[i]);
    int y = get_idx(s2[i]);

    if (x > y) swap(x, y);

    if (x >= 0 && y >= 0) {
      if (x != y && qq.find({x, y}) == qq.end()) {
        qq.insert({x, y});
        queries[x].insert(i);
        queries[y].insert(i);
      } 
    }

    qs[i] = {x, y};
  }

  REP(i, cidx) sort(positions[i].begin(), positions[i].end());
  REP(i, cidx) pq.insert(i);

  while (!pq.empty()) {
    int n = *pq.begin();
    pq.erase(pq.begin());

    for (int x : positions[n]) {
      for (int q : queries[n]) {
        int m = (n == qs[q].first) ? qs[q].second : qs[q].first;

        int to = min((int)(lower_bound(positions[m].begin(), positions[m].end(), x) - positions[m].begin()), 
              (int)positions[m].size() - 1);
        int from = max(0, to - 1);

        int csol = 1000000;
        for (int i = from; i <= to; ++i)
          csol = min(csol, max(x + len[n], positions[m][i] + len[m]) -
                         min(x, positions[m][i]));

        if (sol.count(qs[q]) == 0)
          sol[qs[q]] = csol;
        else
          sol[qs[q]] = min(sol[qs[q]], csol);
      }
    }

    for (int q : queries[n]) {
      int m = (n == qs[q].first) ? qs[q].second : qs[q].first;
      pq.erase(m);
      queries[m].erase(q);
      pq.insert(m);
    }
  }

  REP(i, Q) {
    int x = get_idx(s1[i]);
    int y = get_idx(s2[i]);
    if (x > y) swap(x, y);

    if (x >= 0 && y >= 0) {
      if (x == y) 
        printf("%d\n", len[x]);
      else
        printf("%d\n", sol[make_pair(x, y)]);
    } else {
      puts("-1");
    }
  }

  return 0;
}