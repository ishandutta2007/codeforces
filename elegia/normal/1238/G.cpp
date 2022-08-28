#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>
 
#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename C>
void clr(C& q, C& dq) {
  while (!dq.empty() && dq.top() == q.top()) {
    q.pop();
    dq.pop();
  }
}

void solve() {
  int n, m, c, c0;
  scanf("%d%d%d%d", &n, &m, &c, &c0);
  ll ans = 0;
  priority_queue<pair<int, int>> q, dq;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qq, dqq;
  vector<pair<int, int>> t(n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &t[i].first, &a[i], &b[i]);
    t[i].second = i;
  }
  int curc = c0;
  q.emplace(0, c0);
  qq.emplace(0, c0);
  sort(t.begin(), t.end());
  function<bool(int)> pastTime = [&](int x) {
    curc -= x;
    while (x) {
      clr(qq, dqq);
      if (qq.empty())
        return false;
      if (x >= qq.top().second) {
        x -= qq.top().second;
        ans += qq.top().first * (ll)qq.top().second;
        dq.push(qq.top());
        qq.pop();
      } else {
        ans += qq.top().first * (ll)x;
        dq.push(qq.top());
        pair<int, int> tmp = make_pair(qq.top().first, qq.top().second - x);
        qq.pop();
        q.push(tmp);
        qq.push(tmp);
        x = 0;
      }
    }
    return true;
  };
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int ti = t[i].first, ai = a[t[i].second], bi = b[t[i].second];
    if (!pastTime(ti - cur)) {
      puts("-1");
      return;
    }
    cur = ti;
    while (curc + ai > c && (clr(q, dq), !q.empty() && q.top().first > bi)) {
      if (curc - q.top().second + ai >= c) {
        curc -= q.top().second;
        dqq.push(q.top());
        q.pop();
      } else {
        pair<int, int> tmp = make_pair(q.top().first, c - ai + - curc + q.top().second);
        dqq.push(q.top());
        q.pop();
        q.push(tmp);
        qq.push(tmp);
        curc = c - ai;
      }
    }
    if (curc < c) {
      q.emplace(bi, min(ai, c - curc));
      qq.emplace(bi, min(ai, c - curc));
      curc = min(c, curc + ai);
    }
  }
  if (!pastTime(m - cur)) {
    puts("-1");
    return;
  }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}