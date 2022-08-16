#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int MAX_N = 200000;
const int INF = 1 << 30;

int N;
list< int > g[MAX_N];
int sub[MAX_N];
bool v[MAX_N];
int bit[MAX_N];
int mp[1 << 20], last_update[1 << 20], ween;

int64 all[MAX_N];

int update[MAX_N + 1], ptr = 0;

inline int build_dfs(int idx, int par)
{
  sub[idx] = 1;
  auto it = begin(g[idx]);
  while(it != end(g[idx])) {
    if(v[*it]) {
      it = g[idx].erase(it);
    } else {
      if(*it != par) sub[idx] += build_dfs(*it, idx);
      ++it;
    }
  }
  return (sub[idx]);
}


inline int search_centroid(int idx, int par, const int all)
{
  for(auto &to : g[idx]) {
    assert(!v[to]);
    if(to != par && sub[to] > all) return (search_centroid(to, idx, all));
  }
  return (idx);
}


inline void addd(int idx)
{
  if(last_update[idx] == ween) ++mp[idx];
  else mp[idx] = 1, last_update[idx] = ween;
}

inline int acce(int idx)
{
  if(last_update[idx] != ween) return (0);
  return (mp[idx]);
}


inline int64 rec(int idx, int par, int root_connect, int root_disconnect)
{
  root_connect ^= bit[idx];
  update[ptr++] = root_connect;

  root_disconnect ^= bit[idx];
  int64 sum = acce(root_disconnect);
  for(int i = 0; i < 20; i++) {
    sum += acce(root_disconnect ^ (1 << i));
  }

  for(auto &to : g[idx]) {
    assert(!v[to]);
    if(to == par) continue;
    sum += rec(to, idx, root_connect, root_disconnect);
  }
  all[idx] += sum;
  return (sum);
}

inline void beet(int idx)
{
  for(int i = 0; i < 2; reverse(begin(g[idx]), end(g[idx])), i++) {
    ++ween;
    if(i == 0) addd(bit[idx]);
    for(auto &to: g[idx]) {
      assert(!v[to]);
      ptr = 0;
      auto ret = rec(to, idx, bit[idx], 0);
      if(i == 0) all[idx] += ret;
      for(int j = 0; j < ptr; j++) addd(update[j]);
    }
  }
}

inline void centroid_decomp(int idx)
{
  int centroid = search_centroid(idx, -1, build_dfs(idx, -1) / 2);
  beet(centroid);
  v[centroid] = true;
  for(auto &to : g[centroid]) {
    assert(!v[to]);
    centroid_decomp(to);
  }
}


int main()
{
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  string s;
  cin >> s;
  for(int i = 0; i < N; i++) {
    int c = s[i] - 'a';
    bit[i] = 1 << c;
  }
  memset(last_update, -1, sizeof(last_update));
  centroid_decomp(0);
  for(int i = 0; i < N; i++) {
    printf("%lld ", all[i] + 1);
  }
  puts("");
}