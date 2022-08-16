#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

struct edge
{
  int to, cost;
};

int N, A[200000];
vector< edge > g[200000];

multiset< int64 > q[200000];
int64 add[200000];
int ret[200000];

void rec(int idx, int par = -1)
{
  for(auto &e : g[idx]) {
    if(par == e.to) continue;
    rec(e.to, idx);
    add[e.to] += e.cost;
    while(!q[e.to].empty() && *q[e.to].begin() < add[e.to]) {
      q[e.to].erase(q[e.to].begin());
    }
    if(q[idx].size() < q[e.to].size()) {
      swap(q[idx], q[e.to]);
      swap(add[idx], add[e.to]);
    }
    while(!q[e.to].empty()) {
      q[idx].insert(*q[e.to].begin() - add[e.to] + add[idx]);
      q[e.to].erase(q[e.to].begin());
    }
  }
  ret[idx] = (int) q[idx].size();
  q[idx].insert(A[idx] + add[idx]);
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for(int u = 1; u < N; u++) {
    int v, x;
    scanf("%d %d", &v, &x);
    g[--v].push_back((edge) {u, x});
  }
  rec(0);
  for(int i = 0; i < N; i++) printf("%d ", ret[i]);
  puts("");
}