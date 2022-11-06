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
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct event_t {
  enum evtype { FINISH = 0, ARRIVE = 1 };
  evtype type;
  lint when;
  int id;
  bool operator < (const event_t &o) const {
    if (when != o.when) return when < o.when;
    return type < o.type;
  }
  bool operator > (const event_t &o) const { return o < *this; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, maxtask;
  cin >> n >> maxtask;

  vector<lint> result(n, -1), lenof(n);

  priority_queue<event_t, vector<event_t>, greater<event_t>> pq;
  for (int i = 0; i < n; ++i) {
    int when;
    cin >> when >> lenof[i];
    pq.push({event_t::ARRIVE, when, i});
  }

  bool busy = false;
  queue<int> q;
  while (!pq.empty()) {
    event_t ev = pq.top(); pq.pop();
    lint now = ev.when;
    if (ev.type == event_t::FINISH) {
      busy = false;
      result[ev.id] = now;
    } else {
      if ((int)q.size() < maxtask)
	q.push(ev.id);
    }
    if (!busy && !q.empty()) {
      int newtask = q.front(); q.pop();
      busy = true;
      pq.push({event_t::FINISH, now + lenof[newtask], newtask});
    }    
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << " ";
    cout << result[i];
  }
  cout << "\n";
  
  return 0;
}