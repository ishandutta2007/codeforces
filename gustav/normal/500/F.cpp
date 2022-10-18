#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 4005;
const int MAXB = 4005;
const int MAXT = 20005;
const int MAXQ = 20005;

struct Item {
  int c, h, t;
  void read() {
    scanf("%d%d%d", &c, &h, &t);
  }
};

bool operator<(const Item &a, const Item &b) {
  return a.t < b.t;
}

Item items[MAXN];

int N, P;
int enter[MAXT];
int leave[MAXT];

int Q;
int a[MAXQ];
int b[MAXQ];
int l[MAXQ];
int r[MAXQ];
int sol[MAXQ];
vector< int > qs[MAXT];

int dp_l[MAXN][MAXB];
int dp_r[MAXN][MAXB];

void calc_dp(vector< int > &it, int dp[MAXN][MAXB]) {
  int n = (int)it.size();
  REP(i, MAXB) dp[n][i] = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int b = 0; b < MAXB; ++b) {
      dp[i][b] = dp[i + 1][b];
      if (b >= items[it[i]].c) dp[i][b] = max(dp[i][b], dp[i + 1][b - items[it[i]].c] + items[it[i]].h);
    }
  }
}

void solve(int lo, int hi, vector< int > &queries) {
  if (hi - lo == 1) {
    for (int q : queries) 
      sol[q] = (b[q] >= items[lo].c ? items[lo].h : 0);
    return;
  }

  int mid = (lo + hi) / 2;

  vector< int > queries_l;
  vector< int > queries_r;
  vector< int > queries_now;

  for (int q : queries) {
    if (r[q] < mid) queries_l.push_back(q);
    else if (l[q] >= mid) queries_r.push_back(q);
    else queries_now.push_back(q);
  }

  solve(lo, mid, queries_l);
  solve(mid, hi, queries_r);

  vector< int > items_l;
  vector< int > items_r;

  FOR(i, lo, hi) {
    if (i < mid) items_l.push_back(i);
    else items_r.push_back(i);
  }

  reverse(items_r.begin(), items_r.end());

  calc_dp(items_l, dp_l);
  calc_dp(items_r, dp_r);

  int nl = mid - lo;
  int nr = hi - mid;

  for (int q : queries_now) {
    int pos_l = nl - (mid - l[q]);
    int pos_r = nr - (r[q] - mid + 1);
    for (int i = 0; i <= b[q]; ++i)
      sol[q] = max(sol[q], dp_l[pos_l][i] + dp_r[pos_r][b[q] - i]);
  }
}

int main(void) 
{
  scanf("%d%d", &N, &P);

  REP(i, N) items[i].read();
  sort(items, items + N);

  REP(i, N) {
    enter[items[i].t] += 1;
    leave[items[i].t + P] += 1;
  }

  scanf("%d", &Q);

  REP(i, Q) {
    scanf("%d%d", a + i, b + i);
    qs[a[i]].push_back(i);
  }

  int from = 0;
  int to = -1;

  REP(i, MAXT) {
    to += enter[i];
    from += leave[i];
    for (int q : qs[i]) {
      l[q] = from;
      r[q] = to;
    }
  }

  vector< int > queries;
  REP(i, Q) if (l[i] <= r[i]) queries.push_back(i);

  solve(0, N, queries);

  REP(i, Q) printf("%d\n", sol[i]);

  return 0;
}