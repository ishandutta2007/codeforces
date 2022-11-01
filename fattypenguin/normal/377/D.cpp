#include <functional>
#include <algorithm>
#include <tr1/unordered_map>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 400000;

int n;
int sum[N * 4], suf[N * 4], at[N * 4];

void up(int x) {
  sum[x] = sum[x * 2] + sum[x * 2 + 1];
  suf[x] = max(suf[x * 2 + 1], sum[x * 2 + 1] + suf[x * 2]);
  if (suf[x * 2 + 1] >= sum[x * 2 + 1] + suf[x * 2]) {
    at[x] = at[x * 2 + 1];
  } else {
    at[x] = at[x * 2];
  }
}

void add(int l, int r, int att, int x, int delta) {
  if (l == r) {
    sum[x] += delta;
    suf[x] = max(sum[x], 0);
    at[x] = l;
    return;
  }
  int mid = (l + r) >> 1;
  if (att <= mid) {
    add(l, mid, att, x * 2, delta);
  } else {
    add(mid + 1, r, att, x * 2 + 1, delta);
  }
  up(x);
}

struct Interval {
  int l, mid, r, id;
  Interval(int l, int mid, int r, int id) {
    this->l = l;
    this->r = r;
    this->mid = mid;
    this->id = id;
  }
  Interval() {

  }
};

struct Event {
  int where, id, weight;
  Event(int where, int id, int weight) {
    this->where = where;
    this->id = id;
    this->weight = weight;
  }
  bool operator < (const Event &o) const {
    if (where != o.where) return where > o.where;
    return weight < o.weight;
  }
};

const int UPPER = 310000;

Interval intervals[N];

int main() {
  int n;
  cin >> n;

  vector<Event> events;
  REP(i, n) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    intervals[i] = Interval(a, b, c, i);
    events.PB(Event(c, i, -1));
    events.PB(Event(b, i, 1));
  }
  SORT(events);
  int ans = 0;
  CLEAR(sum);
  CLEAR(at);
  CLEAR(suf);
  TR(it, events) {
    if (it->weight == -1) {
      int which = it->id;
      add(0, UPPER - 1, intervals[which].mid, 1, 1);
      add(0, UPPER - 1, intervals[which].l - 1, 1, -1);
    } else {
      int which = it->id;
      add(0, UPPER - 1, intervals[which].mid, 1, -1);
      add(0, UPPER - 1, intervals[which].l - 1, 1, 1);
    }
    ans = max(ans, suf[1]);
  }
  cout << ans << endl;
  vector<int> res;
  CLEAR(sum);
  CLEAR(at);
  CLEAR(suf);
  TR(it, events) {
    if (it->weight == -1) {
      int which = it->id;
      add(0, UPPER - 1, intervals[which].mid, 1, 1);
      add(0, UPPER - 1, intervals[which].l - 1, 1, -1);
    } else {
      int which = it->id;
      add(0, UPPER - 1, intervals[which].mid, 1, -1);
      add(0, UPPER - 1, intervals[which].l - 1, 1, 1);
    }
      if (suf[1] == ans) {
        int left = at[1], right = it->where;
        REP(i, n) {
          if (intervals[i].l <= left && intervals[i].r >= right
             && intervals[i].mid >= left && intervals[i].mid <= right) {
            res.PB(intervals[i].id);
          }
        }
        break;
      }
  }
  SORT(res);
  REP(i, res.size()) {
    if (i > 0) cout << " ";
    cout << res[i] + 1;
  }
  cout << endl;
  return 0;
}