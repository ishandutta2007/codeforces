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

int N, M, A[300000];
int con[10000001];

int main()
{
  for(int i = 1; i <= 1000000; i++) {
    for(int j = i; j <= 1000000; j += i) {
      ++con[j];
    }
  }

  scanf("%d %d", &N, &M);
  BinaryIndexedTree< int64 > bit(N);
  set< int > st;
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    bit.add(i, A[i]);
    if(con[A[i]] != A[i]) st.emplace(i);
  }
  st.emplace(13333333);
  for(int i = 0; i < M; i++) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    --l, --r;
    if(t == 1) {
      auto it = st.lower_bound(l);
      while(*it <= r) {
        bit.add(*it, -A[*it]);
        A[*it] = con[A[*it]];
        bit.add(*it, A[*it]);
        if(con[A[*it]] != A[*it]) ++it;
        else it = st.erase(it);
      }
    } else {
      printf("%lld\n", bit.sum(r) - bit.sum(l-1));
    }
  }

}