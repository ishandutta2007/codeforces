#include<bits/stdc++.h>

using namespace std;

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

int main()
{
  string S;
  cin >> S;

  CumulativeSum< int > sum(S.size());
  for(int i = 0; i < S.size(); i++) {
    sum.add(i, S[i] == 'a');
  }
  sum.build();

  int ret = 0;

  int latte = 0;
  S += "*";
  for(int i = 0; i < S.size(); i++) {
    int malta = 0;
    for(int j = i; j < S.size(); j++) {
      ret = max(ret, latte + malta + sum.query(133333) - sum.query(j - 1));
      malta += S[j] == 'b';
    }
    latte += S[i] == 'a';
  }
  cout << ret << endl;
}