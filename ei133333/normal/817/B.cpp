#include<bits/stdc++.h>

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
  int N, A[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  BinaryIndexedTree< int64 > bit(N);
  for(int i = 0; i < 3; i++) {
    BinaryIndexedTree< int64 > bit2(N);
    for(int j = 0; j < N; j++) {
      if(A[j] == A[i]) bit2.add(j, i==0?1:bit.sum(j - 1));
    }
    swap(bit, bit2);
  }
  cout << bit.sum(N - 1) << endl;
}