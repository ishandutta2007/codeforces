#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

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
const llint inf = 1000000000000LL;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define MAXN 100005
#define MAXM 100005

typedef pair< int, int > bug;
typedef pair< pair< int, int >, int > student;

int n, m, s;
int a[MAXM];
int b[MAXN];
int c[MAXN];

vector< bug > B;
vector< student > S;

int cc[MAXN];

struct cmp {
  bool operator()(int a, int b) {
    if (cc[a] == cc[b])
      return a < b;
    return cc[a] < cc[b];
  }
};

int sol[MAXM];
int cnt[MAXN];

set< int, cmp > pq;

llint cost(int days) {
  if (days == 0) return 0;
  REP(i, n) cnt[i] = days, cc[i] = S[i].first.second;

  int cs = -1;
  llint ret = 0;

  REP(i, m) {
    while (cs + 1 < n && S[cs + 1].first.first >= B[i].first) 
      pq.insert(++cs);

    if (pq.empty())
      return inf;

    int s = *pq.begin();
    pq.erase(pq.begin());
    ret += cc[s];
    sol[B[i].second] = S[s].second;
    cc[s] = 0;

    if (--cnt[s]) pq.insert(s);
  }

  pq.clear();

  return ret;
}

int main(void)
{
  scanf("%d%d%d", &n, &m, &s);
  REP(i, m) scanf("%d", a + i);
  REP(i, n) scanf("%d", b + i);
  REP(i, n) scanf("%d", c + i);

  REP(i, m) B.push_back({a[i], i});
  REP(i, n) S.push_back({{b[i], c[i]}, i});

  sort(B.rbegin(), B.rend());
  sort(S.rbegin(), S.rend());



  int lo = 1, hi = m + 1, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (cost(mid) > s)
      lo = mid + 1;
    else
      hi = mid;
  }

  cost(lo);

  if (lo == m + 1) 
    puts("NO");
  else {
    puts("YES");
    REP(i, m) printf("%d ", sol[i] + 1);
    puts("");
  }

  return 0;
}