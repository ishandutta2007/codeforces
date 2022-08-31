#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int N;
vector< int > g[200000];
int depth[200000];
bool malta[200000];

void dfs2(int idx, int par = -1)
{
  bool ch = true;
  set< int > vv;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    dfs2(to, idx);
    if(!malta[to]) ch = false;
    depth[idx] = max(depth[idx], depth[to] + 1);
    vv.emplace(depth[to] + 1);
  }
  malta[idx] = ch && vv.size() <= 1;
}

int rec(int idx, int pardist, int par = -1)
{
  map< int, int > ds;
  vector< pair< int, int > > dists;

  int mz = 0;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    ds[depth[to] + 1]++;
    dists.emplace_back(depth[to] + 1, to);
    mz += !malta[to];
  }

  dists.emplace_back(pardist, -1);
  if(pardist > 0) ds[pardist]++;
  sort(dists.rbegin(), dists.rend());

  int ret = INF;

  for(auto &to : g[idx]) {
    if(to == par) continue;
    int chdist = dists[dists[0].second == to].first + 1;
    ds[depth[to] + 1]--;
    if(ds.size() <= 1 || (ds[depth[to] + 1] == 0 && ds.size() <= 2)) {
      if(mz - (!malta[to]) == 0) ret = min(ret, rec(to, chdist, idx));
    }
    ds[depth[to] + 1]++;
  }

  if(mz == 0 && ds.size() <= 2) {
    int get;
    if(ds.size() == 2) get = ds.begin()->first + (--ds.end())->first;
    else get = ds.begin()->first;
    while(get % 2 == 0) get /= 2;
    ret = min(ret, get);
  }
  return(ret);
}


int main()
{
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs2(0);
  auto get = rec(0, 0);
  if(get == INF) cout << -1 << endl;
  else cout << get << endl;
}