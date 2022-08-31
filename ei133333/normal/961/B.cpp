#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

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


int main() {
  int64 N, K;
  int A[100000], T[100000];

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  CumulativeSum< int64 > a(N);
  int64 another = 0;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
    if(T[i] == 1) another += A[i];
    else a.add(i, A[i]);
  }
  a.build();
  int64 ret = 0;
  for(int i = 0; i + K <= N; i++) {
    ret = max(ret, a.query(i+K-1)-a.query(i-1));
  }
  cout << ret + another << endl;
}