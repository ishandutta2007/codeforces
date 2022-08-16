#include<bits/stdc++.h>

using namespace std;

struct SegmentTree
{
  vector< int > seg, lazy;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, 0);
    lazy.assign(2 * sz - 1, 0);
  }

  void push(int k, int l, int r)
  {
    if(lazy[k]) {
      seg[k] = (r - l) - seg[k];
      if(k < sz - 1) {
        lazy[2 * k + 1] ^= 1;
        lazy[2 * k + 2] ^= 1;
      }
      lazy[k] = false;
    }
  }

  void update(int a, int b, int k, int l, int r)
  {
    push(k, l, r);
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      lazy[k] = true;
      push(k, l, r);
      return;
    }
    update(a, b, 2 * k + 1, l, (l + r) >> 1);
    update(a, b, 2 * k + 2, (l + r) >> 1, r);
    seg[k] = seg[2 * k + 1] + seg[2 * k + 2];
  }

  void update(int a, int b)
  {
    update(a, b, 0, 0, sz);
  }

  int query(int a, int b, int k, int l, int r)
  {
    push(k, l, r);
    if(a >= r || b <= l) return (0);
    if(a <= l && r <= b) return (seg[k]);
    return (query(a, b, 2 * k + 1, l, (l + r) >> 1) +
            query(a, b, 2 * k + 2, (l + r) >> 1, r));
  }

  int query(int a, int b)
  {
    return (query(a, b, 0, 0, sz));
  }
};

int N, Q;
vector< int > g[200000];
int in[200000], out[200000], ptr;
char buff[32];

void dfs(int idx)
{
  in[idx] = ptr++;
  for(auto &to : g[idx]) {
    dfs(to);
  }
  out[idx] = ptr;
}

int main()
{
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    int x;
    scanf("%d", &x);
    g[--x].emplace_back(i);
  }
  dfs(0);
  SegmentTree seg(N);
  for(int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    if(x) seg.update(in[i], in[i] + 1);
  }
  scanf("%d", &Q);
  while(Q--) {
    int x;
    scanf("%s %d", buff, &x);
    --x;
    if(buff[0] == 'g') {
      printf("%d\n", seg.query(in[x], out[x]));
    } else {
      seg.update(in[x], out[x]);
    }
  }

}