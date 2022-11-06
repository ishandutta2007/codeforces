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

#define MAXN 100000

using namespace std;

typedef long long lint;

lint value[MAXN], sts[MAXN];
vector<int> adj[MAXN];
bool mark[MAXN];

void calc_sts(int v, int p) {
  sts[v] = 1;
  for (int u : adj[v])
    if (u != p && !mark[u]) {
      calc_sts(u, v);
      sts[v] += sts[u];
    }
}

int find_centroid(int v, int p, int treesize) {
  for (int u : adj[v])
    if (u != p && !mark[u] && sts[u]*2 > treesize)
      return find_centroid(u, v, treesize);
  return v;
}

struct stuff_t {
  lint maxdown = LLONG_MIN, maxpath = LLONG_MIN, maxdownandpath = LLONG_MIN;
};
stuff_t getstuff(int v, int p) {
  stuff_t result;
  lint maxdown0 = value[v], maxdown1 = LLONG_MIN;

  result.maxdownandpath = value[v];

  vector<stuff_t> stuffs;
  
  for (int u : adj[v])
    if (u != p && !mark[u]) {
      stuff_t res = getstuff(u, v);
      lint down = res.maxdown + value[v];
      if (down > maxdown1) {
	maxdown1 = down;
	if (maxdown1 > maxdown0) swap(maxdown0, maxdown1);
      }
      result.maxpath = max(result.maxpath, res.maxpath);
      result.maxdownandpath = max(result.maxdownandpath, value[v] + res.maxdownandpath);
      stuffs.push_back(res);
    }

  {
    int n = stuffs.size();
    int d0 = -1, d1 = -1;
    int p0 = -1, p1 = -1;
    for (int i = 0; i < (int)stuffs.size(); ++i) {
      if (d1 == -1 || (stuffs[i].maxdown > stuffs[d1].maxdown)) {
	d1 = i;
	if (d0 == -1 || (stuffs[i].maxdown > stuffs[d0].maxdown))
	  swap(d0, d1);
      }
      if (p1 == -1 || (stuffs[i].maxpath > stuffs[p1].maxpath)) {
	p1 = i;
	if (p0 == -1 || (stuffs[i].maxpath > stuffs[p0].maxpath))
	  swap(p0, p1);
      }
    }
    vector<int> useful;
    for (int v : {d0, d1, p0, p1})
      if (v != -1)
	useful.push_back(v);
    sort(useful.begin(), useful.end());
    useful.resize(unique(useful.begin(), useful.end())-useful.begin());

    stuff_t zero;
    zero.maxdown = 0;
    zero.maxpath = 0;
    zero.maxdownandpath = 0;
    
    useful.push_back(stuffs.size());
    stuffs.push_back(zero);
    useful.push_back(stuffs.size());
    stuffs.push_back(zero);

    for (int i = 0; i < (int)useful.size(); ++i)
      for (int j = 0; j < (int)useful.size(); ++j)
	if (i != j) {
	  lint res = stuffs[useful[i]].maxpath + stuffs[useful[j]].maxdown + value[v];
	  result.maxdownandpath = max(result.maxdownandpath, res);
	}
  }

  result.maxdown = maxdown0;
  
  if (maxdown1 != LLONG_MIN)
    result.maxpath = max(result.maxpath, maxdown0 + maxdown1 - value[v]);
  else
    result.maxpath = max(result.maxpath, maxdown0);

  result.maxdownandpath = max(result.maxdownandpath, result.maxdown);
  result.maxdownandpath = max(result.maxdownandpath, result.maxpath);
  
  return result;
}

lint solve(int v) {
  calc_sts(v, -1);
  int c = find_centroid(v, -1, sts[v]);
  mark[c] = true;
  
  vector<lint> bestdown(3, 0), bestpath(3, 0);
  vector<stuff_t> stuffs;
  for (int u : adj[c])
    if (!mark[u]) {
      stuffs.push_back(getstuff(u, -1));
      
      lint down = stuffs.back().maxdown;
      if (down > bestdown.back()) {
	bestdown.back() = down;
	for (int i = 2; i > 0 && bestdown[i] > bestdown[i-1]; --i)
	  swap(bestdown[i], bestdown[i-1]);
      }

      lint path = stuffs.back().maxpath;
      if (path > bestpath.back()) {
	bestpath.back() = path;
	for (int i = 2; i > 0 && bestpath[i] > bestpath[i-1]; --i)
	  swap(bestpath[i], bestpath[i-1]);	
      }
    }
  
  lint result = bestpath[0] + bestpath[1];
  for (stuff_t &stuff : stuffs) {
    lint down = stuff.maxdown;
    if (count(bestdown.begin(), bestdown.end(), down) > 0) {
      vector<lint> best = bestdown;
      best.erase(find(best.begin(), best.end(), down));

      lint res0 = stuff.maxpath + (best[0] + value[c] + best[1]);
      result = max(result, res0);

      lint res1 = best[0] + value[c] + stuff.maxdownandpath;
      result = max(result, res1);
    } else {
      lint res = stuff.maxpath + (bestdown[0] + value[c] + bestdown[1]);
      result = max(result, res);
    }
  }

  for (int u : adj[c])
    if (!mark[u])
      result = max(result, solve(u));

  result = max(result, bestdown[0] + value[c] + bestdown[1]);  

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> value[i];

  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b; --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; ++i) mark[i] = false;
  cout << solve(0) << "\n";
  
  return 0;
}