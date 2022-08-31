#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int mod = 1e9 + 7;

int64 dp[1000001];

int64 f(int64 k)
{
  if(k == 1) return (1);
  vector< int64 > v;
  for(int64 i = 1; i * i <= k; i++) {
    if(k % i == 0) {
      v.push_back(i);
      if(i * i != k) v.push_back(k / i);
    }
  }
  sort(begin(v), end(v));
  reverse(begin(v), end(v));
  for(int i = 0; i < v.size(); i++) {
    dp[i] = k / v[i] + 1;
    for(int j = 0; j < i; j++) {
      if(v[j] % v[i] == 0) dp[i] -= dp[j];
    }
  }
  return (dp[v.size() - 1]);
}

int main()
{
  int64 n, k;
  cin >> n >> k;
  for(int64 i = 1; i <= k && n != 1; i++) {
    if(i & 1) n = f(n);
  }
  cout << n % mod << endl;
}