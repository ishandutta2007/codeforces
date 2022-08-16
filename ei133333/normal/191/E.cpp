#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

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
  int64 K;
  int64 A[100000];

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int64 sum = 0;
  vector< int64 > beet(1, 0);
  for(int i = 0; i < N; i++) {
    sum += A[i];
    beet.emplace_back(sum);
  }

  vector< int64 > vs(beet);
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));

  vector< int > rev(N + 1);
  for(int i = 0; i < beet.size(); i++) {
    auto p = lower_bound(begin(vs), end(vs), beet[i]) - begin(vs);
    rev[i] = p;
  }


  int64 ok = -(1LL << 61), ng = 1LL << 61;

  auto check = [&](int64 v)
  {
    BinaryIndexedTree< int > bit(vs.size());
    for(int i = 0; i < N + 1; i++) {
      bit.add(rev[i], 1);
    }

    int64 ret = 0;
    for(int i = 0; i < N; i++) {
      bit.add(rev[i], -1);
      auto p = lower_bound(begin(vs), end(vs), beet[i] + v) - begin(vs);
      ret += bit.sum(vs.size() - 1) - bit.sum(p - 1);
    }
    return (ret >= K);
  };

  while(ng - ok > 1) {
    int64 mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;

}