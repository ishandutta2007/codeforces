#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct UnionFindRange
{
  vector< int > data;
  vector< int > left, right;

  UnionFindRange(vector< int > &vs)
  {
    data.assign(vs.size(), -1);
    left = vs;
    right = vs;
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

  pair< int, int > range(int k)
  {
    k = find(k);
    return {left[k], right[k]};
  };

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

int main()
{
  int N;
  string S;

  cin >> N;
  vector< int > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    --A[i];
  }
  cin >> S;

  UnionFindRange uf(A);
  for(int i = 1; i < N; i++) {
    if(S[i - 1] == '1') uf.unite(i - 1, i);
  }

  vector< int > vs;
  for(int i = 0; i < N; i++) {
    if(uf.find(i) == i) {
      auto p = uf.range(i);
      vs.emplace_back(p.first);
      vs.emplace_back(p.second);
    }
  }

  if(is_sorted(begin(vs), end(vs))) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}