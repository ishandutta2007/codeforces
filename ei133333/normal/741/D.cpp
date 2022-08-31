#include <bits/stdc++.h>

using namespace std;

struct edge
{
  int to, mask;
};

int N;
vector< edge > g[500000];
int subtree[500000], best[500000];

int ret[500000];
unordered_map< int, int > buff[500000];
int lazy[500000], addd[500000];


void update(int idx)
{
  subtree[idx] = 1;

  if(!g[idx].empty()) {
    for(auto &e : g[idx]) {
      ret[idx] = max(ret[idx], ret[e.to]);
      subtree[idx] += subtree[e.to];
    }

    for(auto i = 1; i < g[idx].size(); i++) {
      if(subtree[g[idx][0].to] < subtree[g[idx][i].to]) {
        swap(g[idx][0], g[idx][i]);
      }
    }

    auto &heavy = g[idx][0];
    swap(buff[heavy.to], buff[idx]);
    lazy[idx] = lazy[heavy.to] ^ heavy.mask;
    addd[idx] = addd[heavy.to] + 1;

    for(auto &e : g[idx]) {
      if(heavy.to == e.to) continue;
      for(auto &x : buff[e.to]) {
        const int bit = x.first ^lazy[e.to] ^e.mask ^lazy[idx];
        const int val = x.second + 1 + addd[e.to];// - addd[idx];
        for(int i = 0; i < 22; i++) {
          const int bb = bit ^(1 << i);
          if(buff[idx].count(bb)) ret[idx] = max(ret[idx], buff[idx][bb] + addd[idx] + val);
        }
        if(buff[idx].count(bit))
          ret[idx] = max(ret[idx], buff[idx][bit] + addd[idx] + val);
      }
      for(auto &x : buff[e.to]) {
        const int bit = x.first ^lazy[e.to] ^e.mask ^lazy[idx];
        const int val = x.second + 1 + addd[e.to] - addd[idx];
        if(buff[idx].count(bit)) buff[idx][bit] = max(buff[idx][bit], val);
        else buff[idx][bit] = val;
      }
      // buff[e.to].clear();
    }

    for(int i = 0; i < 22; i++) {
      const int bb = (1 << i) ^lazy[idx];
      if(buff[idx].count(bb)) ret[idx] = max(ret[idx], buff[idx][bb] + addd[idx]);
    }
    if(buff[idx].count(lazy[idx]))
      ret[idx] = max(ret[idx], buff[idx][lazy[idx]] + addd[idx]);
  }
  if(!buff[idx].count(lazy[idx])) buff[idx][lazy[idx]] = -addd[idx];
}

int main()
{
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    int A;
    char B;
    scanf("%d %c", &A, &B);
    g[--A].push_back((edge) {i, 1 << int(B - 'a')});
  }
  for(int i = N - 1; i >= 0; i--) update(i);
  for(int i = 0; i < N; i++) {
    printf("%d%c", ret[i], " \n"[i == N - 1]);
  }
}