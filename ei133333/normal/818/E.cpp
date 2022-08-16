#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

map< int64, int > prime_factor(int64 n)
{
  map< int64, int > ret;
  for(int64 i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

void solve()
{
  int N, K, A[100000];

  cin >> N >> K;

  auto pdf = prime_factor(K);
  if(pdf.empty()) pdf[1] = 0;
  vector< vector< char > > range(N, vector< char >(pdf.size(), 0));

  for(int i = 0; i < N; i++) {
    cin >> A[i];
    int ptr = 0;
    if(K > 1) {
      for(auto &p : pdf) {
        while(A[i] % p.first == 0) {
          A[i] /= p.first;
          range[i][ptr]++;
          if(range[i][ptr] == p.second) break;
        }
        ++ptr;
      }
    }
  }


  vector< int > odd;
  for(auto &p : pdf) {
    odd.emplace_back(p.second);
  }

  int64 ret = 0;
  vector< int > shake(pdf.size(), 0), sum(pdf.size(), 0);
  int big = 0;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < odd.size(); j++) {
      while(shake[j] <= i || (shake[j] < N && sum[j] < odd[j])) sum[j] += range[shake[j]++][j];
      if(sum[j] < odd[j]) goto foo;
      big = max(big, shake[j]);
    }
    ret += N - big + 1;
    for(int j = 0; j < odd.size(); j++) {
      sum[j] -= range[i][j];
    }
  }
  foo:;
  cout << ret << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}