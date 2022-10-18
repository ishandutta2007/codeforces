#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back

#define BSZ 320
#define MAXN 100005

int cnt[BSZ][MAXN];

deque< int > bkt[BSZ];
vector< int > a;

void rebuild() {
  a.clear();
  for (int i = 0; i < BSZ; ++i) 
    for (auto j : bkt[i])
      a.pb(j);
  
  for (int i = 0; i < BSZ; ++i) 
    bkt[i].clear();

  int cb = 0;
  for (auto i : a) {
    bkt[cb].pb(i);
    ++cnt[cb][i];
    if (bkt[cb].size() == BSZ) ++cb;
  }
}

pair< int, int > kth(int k) { // (bucket, idx)
  for (int i = 0; i < BSZ; ++i) {
    if (bkt[i].size() <= k) {
      k -= bkt[i].size();
    } else {
      return make_pair(i, k);
    }
  }
  assert(false);
  return make_pair(-1, -1);
}

int query(int l, int r, int v) {
  pair< int, int > L = kth(l);
  pair< int, int > R = kth(r);

  int ret = 0;
  if (L.first == R.first) {
    for (int i = L.second; i <= R.second; ++i) 
      ret += (bkt[L.first][i] == v);
  } else {
    for (int i = L.first + 1; i < R.first; ++i) 
      ret += cnt[i][v];

    for (int i = L.second; i < bkt[L.first].size(); ++i)
      ret += (bkt[L.first][i] == v);
    
    for (int i = 0; i <= R.second; ++i)
      ret += (bkt[R.first][i] == v);
  }

  return ret;
}

void output() {
  for (int j = 0; j < BSZ; ++j) {
    printf("[");
    for (int i = 0; i < bkt[j].size(); ++i)
      printf("%d ", bkt[j][i]);
    printf("] ");
  }
  puts("");
}

void update(int l, int r) {
  pair< int, int > L = kth(l);
  pair< int, int > R = kth(r);

  int v = bkt[R.first][R.second];
  --cnt[R.first][v];
  bkt[R.first].erase(bkt[R.first].begin() + R.second);

  for (int i = L.first + 1; i <= R.first; ++i) {
    --cnt[i - 1][bkt[i - 1].back()];
    ++cnt[i][bkt[i - 1].back()];
    bkt[i].push_front(bkt[i - 1].back());
    bkt[i - 1].pop_back();
  }

  ++cnt[L.first][v];
  bkt[L.first].insert(bkt[L.first].begin() + L.second, v);
}

int main(void)
{
  int N, M, x, type, l, r, k;

  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    scanf("%d", &x);
    bkt[0].pb(x);
  }

  rebuild();

  scanf("%d", &M);

  int lastans = 0;
  for (int i = 0; i < M; ++i) {
    scanf("%d", &type);

    if (type == 1) {
      scanf("%d%d", &l, &r);
      l = (l + lastans - 1) % N;
      r = (r + lastans - 1) % N;
      if (l > r) swap(l, r);
      update(l, r);
    } else {
      scanf("%d%d%d", &l, &r, &k);
      l = (l + lastans - 1) % N;
      r = (r + lastans - 1) % N;
      if (l > r) swap(l, r);
      k = (k + lastans - 1) % N + 1;
      printf("%d\n", lastans = query(l, r, k));
    }
  }

  return 0;
}