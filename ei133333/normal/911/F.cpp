#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int N;
vector< int > g[200000];

pair< int, int > dfs(int idx, int prev)
{
  pair< int, int > ret = make_pair(0, idx);
  for(int to : g[idx]) {
    if(to != prev) {
      pair< int, int > cost = dfs(to, idx);
      cost.first++;
      ret = max(ret, cost);
    }
  }
  return (ret);
}

vector< int > line;
int beet;
bool v[200000];

bool dfs2(int idx, int par = -1)
{
  if(idx == beet) {
    v[idx] = true;
    line.push_back(idx);
    return (true);
  }
  for(auto &to : g[idx]) {
    if(to == par) continue;
    if(dfs2(to, idx)) {
      v[idx] = true;
      line.push_back(idx);
      return (true);
    }
  }
  return (false);
}

vector< int > bfs(int idx)
{
  vector< int > latte(N, -1);
  queue< int > que;
  latte[idx] = 0;
  que.push(idx);
  while(!que.empty()) {
    int p = que.front();
    que.pop();
    for(auto &to : g[p]) {
      if(latte[to] == -1) {
        latte[to] = latte[p] + 1;
        que.emplace(to);
      }
    }
  }
  return (latte);
}


int main()
{
  cin >> N;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  auto p = dfs(0, -1);
  auto q = dfs(p.second, -1);
  beet = q.second;
  dfs2(p.second);

  auto latte = bfs(p.second);
  auto malta = bfs(q.second);

  int64 ret = 0;
  vector< tuple< int, int, int > > ev;
  for(int i = 0; i < N; i++) {
    if(v[i]) continue;
    if(latte[i] > malta[i]) ev.emplace_back(latte[i], i, p.second);
    else ev.emplace_back(malta[i], i, q.second);
    ret += max(latte[i], malta[i]);
  }
  sort(ev.rbegin(), ev.rend());

  while(line.size() > 1) {
    ret += malta[line.back()];
    ev.emplace_back(-1, line.back(), line.front());
    line.pop_back();
  }


  cout << ret << endl;
  for(auto &s : ev) {
    int a, b, c;
    tie(a, b, c) = s;
    cout << b + 1 << " " << c + 1 << " " << b + 1 << endl;
  }
}