#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

struct UnionFind
{
  vector< int > data;
  vector< int > left, right;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
    left.resize(sz);
    right.resize(sz);
    for(int i = 0; i < sz; i++) left[i] = i;
    for(int i = 0; i < sz; i++) right[i] = i;
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    left[x] = min(left[x], left[y]);
    right[x] = max(right[x], right[y]);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

const int INF = 1 << 30;

int N, A[200000];
int latte[31][200000], malta[31][200000];

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector< int > order(N);
  iota(begin(order), end(order), 0);
  sort(begin(order), end(order), [&](int a, int b)
  {
    if(A[a] == A[b]) return (a < b);
    return (A[a] < A[b]);
  });

  for(int j = 0; j < 31; j++) {
    for(int i = 0; i < N; i++) {
      if((A[i] >> j) & 1) malta[j][i] = i;
      else if(i == 0) malta[j][i] = -INF;
      else malta[j][i] = malta[j][i - 1];
    }
    for(int i = N - 1; i >= 0; i--) {
      if((A[i] >> j) & 1) latte[j][i] = i;
      else if(i == N - 1) latte[j][i] = INF;
      else latte[j][i] = latte[j][i + 1];
    }
  }

  UnionFind uf(N);
  bool live[200000] = {};
  int64 ret = 0;
  for(int i : order) {
    int left = -INF, right = INF;
    for(int j = 0; j < 31; j++) {
      if((A[i] >> j) & 1) continue;
      left = max(left, malta[j][i]);
      right = min(right, latte[j][i]);
    }
    if(i > 0 && live[i - 1]) uf.unite(i, i - 1);
    if(i + 1 < N && live[i + 1]) uf.unite(i, i + 1);
    const auto LL = uf.left[uf.find(i)];
    const auto RR = uf.right[uf.find(i)];
    const auto beet1 = max(0, left - LL + 1);
    const auto beet2 = max(0, RR - right + 1);
    ret += 1LL * beet1 * (RR - i + 1);
    ret += 1LL * beet2 * (i - LL + 1);
    ret -= 1LL * beet1 * beet2;
    live[i] = true;
  }
  cout << ret << endl;
}