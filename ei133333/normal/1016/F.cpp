#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

struct edge {
  int to, cost;
};


int N, M;
vector< edge > g[300000];
vector< int > path;

bool dfs(int idx, int par) {
  if(idx + 1 == N) {
    path.push_back(idx);
    return true;
  }
  for(auto &e : g[idx]) {
    if(e.to == par) continue;
    if(dfs(e.to, idx)) {
      path.push_back(idx);
      return true;
    }
  }
  return false;
}

int dfs2(int idx, int par) {
  int ret = 1;
  for(auto &e : g[idx]) {
    if(e.to == par) continue;
    ret += dfs2(e.to, idx);
  }
  return ret;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 1; i < N; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    --x, --y;
    g[x].push_back((edge) {y, z});
    g[y].push_back((edge) {x, z});
  }
  dfs(0, -1);


  reverse(begin(path), end(path));
  vector< int64 > cost(path.size());
  int64 all = 0;
  for(int i = 1; i < path.size(); i++) {
    for(auto &e : g[path[i]]) {
      if(e.to == path[i - 1]) {
        cost[i] = e.cost;
        all += e.cost;
      }
    }
  }


  for(int i = 0; i < path.size(); i++) {
    int child_size = (int) g[path[i]].size();
    if(i > 0) --child_size;
    if(i + 1 < path.size()) --child_size;
    if(child_size >= 2) {
      for(int j = 0; j < M; j++) cout << all << endl;
      return 0;
    }
  }

  for(int i = 0; i < path.size(); i++) {
    int latte = i == 0 ? -1 : path[i - 1];
    int malta = i + 1 == path.size() ? -1 : path[i + 1];
    for(auto &e : g[path[i]]) {
      if(e.to == latte || e.to == malta) continue;
      if(dfs2(e.to, path[i]) >= 2) {
        for(int j = 0; j < M; j++) cout << all << endl;
        return 0;
      }
    }
  }

  int64 adjust = INF;
  for(int i = 2; i < path.size(); i++) {
    adjust = min(adjust, cost[i - 1] + cost[i]);
  }

  vector< int64 > cost2(path.size());
  for(int i = 0; i < path.size(); i++) {
    int latte = i == 0 ? -1 : path[i - 1];
    int malta = i + 1 == path.size() ? -1 : path[i + 1];
    for(auto &e : g[path[i]]) {
      if(e.to == latte || e.to == malta) continue;
      cost2[i] = e.cost;
    }
  }

  vector< int64 > prefix(path.size());
  int64 sum = 0;
  for(int i = 0; i < path.size(); i++) {
    sum += cost[i];
    prefix[i] = cost2[i] + sum;
    if(i > 0) prefix[i] = max(prefix[i], prefix[i - 1]);
  }
  sum = 0;
  vector< int64 > suffix(path.size());
  for(int i = (int) path.size() - 1; i >= 0; i--) {
    suffix[i] = cost2[i] + sum;
    if(i + 1 < path.size()) suffix[i] = max(suffix[i], suffix[i + 1]);
    sum += cost[i];
  }
  int64 best = 0;
  for(int i = 1; i < path.size(); i++) {
    bool f = cost2[i - 1] > 0 || cost2[i] > 0;
    if(f) best = max(best, prefix[i - 1] + suffix[i]);
    else if(i + 1 < path.size()) best = max(best, prefix[i - 1] + suffix[i + 1]);
  }


  for(int i = 0; i < M; i++) {
    int64 x;
    scanf("%lld", &x);
    int64 ret = all;
    if(adjust != INF) {
      ret = min(ret, max(all - adjust + x, best + x));
    } else {
      ret = min(ret, best + x);
    }
    printf("%lld\n", ret);
  }

}