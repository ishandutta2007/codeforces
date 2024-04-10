#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
template<typename T>
struct DiameterForVertex{
  vector<T> vs,dp;
  vector<vector<int> > G;
  DiameterForVertex(const vector<T> &vs, const vector<vector<int> > &G) : vs(vs), dp(vs.size()), G(G) {}
  void dfs(int v,int p,int &s){
    if(p<0) dp[v]=T(0);
    dp[v]+=vs[v];
    if(dp[s]<dp[v]) s=v;
    for(int u:G[v]){
      if(u==p) continue;
      dp[u]=dp[v];
      dfs(u,v,s);
    }
  }
  T build(){
    assert(!vs.empty());
    int s=0;
    dfs(s,-1,s);
    dfs(s,-1,s);
    return dp[s];
  }
  T build(vector<T> us){
    assert(us.size()==dp.size());
    vs=us;
    return build();
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<set<int> > st(n);
    REP(_, n - 1) {
      int x, y; cin >> x >> y; --x; --y;
      st[x].emplace(y);
      st[y].emplace(x);
    }
    if (n == 2) {
      cout << 2 << '\n';
      continue;
    }
    vector<int> rem, weight(n, 1);
    vector<vector<int> > kesu(n);
    REP(i, n) {
      if (st.size() == 1) {
        kesu[*st[i].begin()].emplace_back(i);
        ++weight[*st[i].begin()];
      } else {
        rem.emplace_back(i);
      }
    }
    REP(i, n) {
      for (int e : kesu[i]) st[i].erase(e);
    }
    map<int, int> mp;
    REP(i, rem.size()) mp[rem[i]] = i;
    vector<vector<int> > graph(rem.size());
    REP(i, n) if (mp.count(i) == 1) {
      for (int e : st[i]) graph[mp[i]].emplace_back(mp[e]);
    }
    vector<long long> w(rem.size());
    REP(i, n) {
      if (mp.count(i) == 1) w[mp[i]] = weight[i];
    }
    REP(i, rem.size()) w[i] += max((int)graph[i].size() - 2, 0);
    DiameterForVertex<long long> dia(w, graph);
    cout << dia.build() << '\n';
  }
  return 0;
}