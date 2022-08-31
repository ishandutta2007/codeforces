#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

const int INF = 1 << 30;

template< class T >
struct BinaryIndexedTree1
{
  vector< T > data;

  BinaryIndexedTree1(int sz)
  {
    data.assign(++sz, -INF);
  }

  T sum(int k)
  {
    T ret = -INF;
    for(++k; k > 0; k -= k & -k) ret = max(ret, data[k]);
    return (ret);
  }

  void add(int k, T x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] = max(data[k], x);
  }
};


template< class T >
struct BinaryIndexedTree2
{
  vector< T > data;

  BinaryIndexedTree2(int sz)
  {
    data.assign(++sz, INF);
  }

  T sum(int k)
  {
    T ret = INF;
    for(++k; k > 0; k -= k & -k) ret = min(ret, data[k]);
    return (ret);
  }

  void add(int k, T x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] = min(data[k], x);
  }
};

template< class T >
struct CumulativeSum
{
  vector< T > data;

  CumulativeSum(int sz) : data(sz, 0) {};

  void add(int k, int x)
  {
    data[k] += x;
  }

  void build()
  {
    for(int i = 1; i < data.size(); i++) {
      data[i] += data[i - 1];
    }
  }

  T query(int k)
  {
    if(k < 0) return (0);
    return (data[min(k, (int) data.size() - 1)]);
  }
};

int N, A[1000000], Latte[1000000], Malta[1000000];
int latte[1000000], malta[1000000];
vector< int > appear[1000001];

int main()
{
  scanf("%d", &N);
  CumulativeSum< int64 > sum(N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    sum.add(i, A[i]);
    appear[A[i]].push_back(i);
  }
  sum.build();
  BinaryIndexedTree1< int > bit1(1000001);
  BinaryIndexedTree2< int > bit2(1000001);
  BinaryIndexedTree1< int > bit3(1000001);
  BinaryIndexedTree2< int > bit4(1000001);

  for(int i = 0; i < N; i++) {
    Latte[i] = max(-1, bit1.sum(A[i]));
    bit1.add(A[i], i);
  }
  for(int i = N - 1; i >= 0; i--) {
    Malta[i] = min(N, bit2.sum(A[i] - 1));
    bit2.add(A[i], i);
  }
  for(int i = 0; i < N; i++) {
    A[i] = 1000001 - A[i];
  }
  for(int i = 0; i < N; i++) {
    latte[i] = max(-1, bit3.sum(A[i]));
    bit3.add(A[i], i);
  }
  for(int i = N - 1; i >= 0; i--) {
    malta[i] = min(N, bit4.sum(A[i] - 1));
    bit4.add(A[i], i);
  }

  int64 ret = 0;
  for(int i = 0; i < 1000001; i++) {
    for(int j : appear[i]) {
      int64 L = Latte[j] + 1;
      int64 R = Malta[j] - 1;
      ret -= (R - j + 1) * (j - L + 1) * i;
    }
    for(int j : appear[i]) {
      int64 L = latte[j] + 1;
      int64 R = malta[j] - 1;
      ret += (R - j + 1) * (j - L + 1) * i;
    }
  }
  cout << ret << endl;
}