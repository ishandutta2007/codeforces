#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

template< class T >
struct BinaryIndexedTree
{
  vector< T > data;

  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }

  T sum(int k)
  {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main()
{
  int N;
  vector< int > A[100005];

  cin >> N;
  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    A[K].emplace_back(i);
  }

  int64 ret = 0, head = 0;
  BinaryIndexedTree< int > bit(N);
  for(int i = 0; i < N; i++) bit.add(i, 1);

  auto SUM = [&](int left, int right)
  {
    if(left <= right) return (bit.sum(right) - bit.sum(left - 1));
    return (bit.sum(N - 1) - bit.sum(left - 1) + bit.sum(right));
  };
  for(int i = 0; i < 100005; i++) {
    if(A[i].empty()) continue;
    auto now = lower_bound(begin(A[i]), end(A[i]), head);
    if(now == end(A[i])) now = begin(A[i]);
    const int pos = now - begin(A[i]);
    for(int j = 0; j < A[i].size(); j++) {
      int beet = A[i][(j + pos) % A[i].size()];
      ret += SUM(head, beet);
      bit.add(beet, -1);
      head = beet;
    }
  }
  cout << ret << endl;
}