#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <sstream>
#include <memory.h>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<pair<int, int>> g[100005];
bool used[100005];
int pr[100005], d[100005];
deque<int> q; 

string ans = "";
vector<int> way;

int dist[100005], len[100005];
vector<pair<pair<int, int>, pair<int, int>>> ed;

int mod = 1000000007;
int base = 31;

int main() {
  base = 31 + rand() % 256;
  if (base % 2 == 0) ++base;

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back({c, b});
    g[b].push_back({c, a});
  }
  for (int i = 0; i < n; ++i)
    sort(g[i].begin(), g[i].end());

  q.push_back(n - 1);
  used[n - 1] = true;
  memset(pr, -1, sizeof(pr));
  while (q.size()) {
    int x = q.front(); q.pop_front();
    // cout << x.first << endl;
    for (auto p : g[x]) {
      if (!used[p.second]) {
        if (p.first == 0) {
          q.push_back(p.second);
        } else {
          continue;
        }
        dist[p.second] = dist[x] + 1;
        used[p.second] = true;
        pr[p.second] = x;
        d[p.second] = p.first;
      }
    }
  }
  for (int i = 0; i < n; ++i)
    if (used[i])
      q.push_back(i);
  q.push_back(-1);
  /*for (int i = 0; i < n; ++i) {
    if (used[i]) {
      for (auto p : g[i]) {
        ed.push_back({{p.first, dist[i]}, {i, p.second}});
        // cout << "Used:  " << i << " " << p.first << " " << p.second << endl;
      }
    }
  }
  sort(ed.begin(), ed.end());
  int prd = -1;
  for (auto e : ed) {
    // g[n - 1].push_back({e.second.second, e.first});
    if (!used[e.second.second]) {
        if (e.first.first != prd) {
          // cout << "Add: " << -1 << endl;
          q.push_back(-1);
        }
        // cout << "Add: " << e.second.second << " " << e.first.first << endl;
        q.push_back(e.second.second);
        used[e.second.second] = true;
        pr[e.second.second] = e.second.first;
        d[e.second.second] = e.first.first;
        dist[e.second.second] = dist[e.second.first] + 1;
        len[e.second.second] = len[e.second.first] + 1;
        prd = e.first.first;
        // cout << e.second.second << "  " << e.second.first << endl;
      }
  }
  q.push_back(-1);*/
  // cout << q.size() << endl;
  // return 0;
  // q.push_back({n - 1, 1});
  while (q.size()) {
    int x = q.front();
    ed.clear();
    while (q.size() && q.front() != -1) { //d[q.front()] == d[x] && len[q.front()] == len[x]) {
      // cout << q.front() << endl;
      for (auto p : g[q.front()]) {
        ed.push_back({{p.first, dist[q.front()]}, {q.front(), p.second}}); // meybe len -> dist
      }
      q.pop_front();
    }
    // cout << q.front() << endl;
    // if (q.size())
    q.pop_front();
    sort(ed.begin(), ed.end());

    int prd = -1;
    for (auto e : ed) {
      if (!used[e.second.second]) {
        if (e.first.first != prd) {
          // cout << "Add: " << -1 << endl;
          q.push_back(-1);
        }
        // cout << "Add: " << e.second.second << endl;
        q.push_back(e.second.second);
        used[e.second.second] = true;
        pr[e.second.second] = e.second.first;
        d[e.second.second] = e.first.first;
        dist[e.second.second] = dist[e.second.first] + 1;
        len[e.second.second] = len[e.second.first] + 1;
        // cout << e.second.second << "  " << e.second.first << endl;
        prd = e.first.first;
      }
    }
    if (ed.size())
      q.push_back(-1);
  }
  // return 0;
  int cur = 0;
  while (pr[cur] != -1) {
    ans += '0' + d[cur];
    way.push_back(cur);
    cur = pr[cur];
  }
  way.push_back(cur);
  while (ans.size() > 1 && ans.back() == '0')
    ans.pop_back();
  reverse(ans.begin(), ans.end());
  
  // ans += string(n + 2, '0');
  // // cout << ans << endl;
  // q.clear();
  // memset(used, 0, sizeof(used));
  // memset(pr, -1, sizeof(pr));
  // memset(dist, 0, sizeof(dist));
  // q.push_back(0);
  // used[0] = true;
  // while(q.size()) {
  //   int x = q.front(); q.pop_front();
  //   for (auto p : g[x]) {
  //     if (p.first == ans[dist[x]] - '0' && !used[p.second]) {
  //       q.push_back(p.second);
  //       used[p.second] = true;
  //       pr[p.second] = x;
  //       dist[p.second] = dist[x] + 1;
  //       d[p.second] = p.first;
  //       // cout << x << " -> " << p.second << endl;
  //     }
  //   }
  // }

  // ans.clear(); way.clear();
  // cur = n - 1;
  // while (pr[cur] != -1) {
  //   if (ans.size() || d[cur] != 0)
  //     ans += '0' + d[cur];
  //   way.push_back(cur);
  //   cur = pr[cur];
  // }
  // way.push_back(cur);
  // reverse(way.begin(), way.end());

  printf("%s\n", ans.c_str());
  printf("%d\n", way.size());
  for (int i = 0; i < way.size(); ++i) {
    if (i) printf(" ");
    printf("%d", way[i]);
  }
  printf("\n");
  return 0;
}