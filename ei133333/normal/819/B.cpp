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
  int N, P[1000000];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &P[i]), --P[i];

  int T[1000000];
  for(int i = 0; i < N; i++) T[i] = P[i] - i;


  int64 ret = numeric_limits< int64 >::max();
  int id;

  int64 now = 0LL;
  for(int i = 0; i < N; i++) now += abs(T[i]);

  BinaryIndexedTree< int > bit(N + N + N+1);
  for(int i = 0; i < N; i++) T[i] += N;

  for(int i = 0; i < N; i++) bit.add(T[i], 1);

  for(int i = 0; i < N; i++) {

    if(ret > now) {
      ret = now;
      id = i;
    }
    int base_line = i + N + 1;
    now += bit.sum(base_line - 1);
    now -= bit.sum(N + N + N) - bit.sum(base_line - 1);
    int get = T[N - i - 1];
    bit.add(get, -1);
    now -= abs(get - base_line);
    bit.add(get + N, 1);
    now += abs(N + get - base_line);
  }

  cout << ret << " " << id << endl;
}