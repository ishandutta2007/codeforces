#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

struct BinaryIndexedTree
{
  vector< int64 > data;

  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }

  int64 sum(int k)
  {
    int64 ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, int x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

struct BinaryIndexedTree2D
{
  vector< BinaryIndexedTree > data;

  BinaryIndexedTree2D(int W, int H)
  {
    data.resize(++W, BinaryIndexedTree(H));
  }

  int64 sum(int k, int y)
  {
    int64 ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k].sum(y);
    return (ret);
  }

  int64 add(int k, int y, int x)
  {
    for(++k; k < data.size(); k += k & -k) data[k].add(y, x);
  }
};

int N, M, K, Q;
vector< tuple< int, int, int > > lines[2000];
int x1[1000000], y1[1000000], x2[1000000], y2[1000000];
int64 ret[1000000];

int main()
{
  scanf("%d %d %d", &N, &M, &K);

  for(int i = 0; i < K; i++) {
    int p;
    scanf("%d", &p);
    while(p--) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      lines[i].emplace_back(x, y, z);
    }
  }

  vector< int > flip[2000];
  vector< int > query;

  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    char buff[64];
    scanf(" %s", buff);
    if(buff[0] == 'S') {
      int idx;
      scanf("%d", &idx);
      flip[--idx].push_back(i);
    } else {
      scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
      --x1[i], --y1[i];
      query.push_back(i);
    }
  }

  BinaryIndexedTree2D bit(N + 2, M + 2);
  for(int i = 0; i < K; i++) {
    for(auto& k : lines[i]) {
      int x, y, z;
      tie(x, y, z) = k;
      bit.add(x, y, z);
    }
    bool add = true;
    int a = 0, b = 0;
    while(a < query.size()) {
      if(b == flip[i].size() || query[a] < flip[i][b]) {
        const int j = query[a++];
        if(!add) continue;
        ret[j] += bit.sum(x2[j], y2[j]) - bit.sum(x2[j], y1[j]) - bit.sum(x1[j], y2[j]) + bit.sum(x1[j], y1[j]);
      } else {
        add ^= 1;
        ++b;
      }
    }
    for(auto& k : lines[i]) {
      int x, y, z;
      tie(x, y, z) = k;
      bit.add(x, y, -z);
    }
  }

  for(int i : query) {
    printf("%I64d\n", ret[i]);
  }
}