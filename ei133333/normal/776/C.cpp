#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 limit = 1LL << 57;

int64 N, K;
int64 A[100000];

int64 get(vector< int64 >& x)
{
  map< int64, int > dp;
  dp[0] = 1;
  int64 sum = 0, ret = 0;
  for(int i = 0; i < N; i++) {
    sum += A[i];
    for(auto& v : x) {
      if(dp.count(sum - v)) ret += dp[sum - v];
    }
    dp[sum]++;
  }
  return(ret);
}

int main()
{
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];

  int64 ret = 0;
  vector< int64 > vect;

  if(K == -1) {
    vect.push_back(-1);
    vect.push_back(1);
  } else if(K == 1) {
    vect.push_back(1);
  } else {
    int64 now = 1;
    while(now < limit) {
      vect.push_back(now);
      now *= K;
    }
  }
  cout << get(vect) << endl;
}