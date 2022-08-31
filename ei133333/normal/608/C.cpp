#include<bits/stdc++.h>
using namespace std;
typedef pair< int, int > Pi;

int dp[100000];
int N;
vector< Pi > data;

int rec(int idx)
{
  if(idx <= 0) return(0);
  if(~dp[idx]) return(dp[idx]);
  int pos = lower_bound(data.begin(), data.end(), Pi(data[idx].first - data[idx].second, 0)) - data.begin();
  return(dp[idx] = rec(pos - 1) + idx - pos);
}

int main()
{
  memset(dp, -1, sizeof(dp));

  cin >> N;
  data.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> data[i].first >> data[i].second;
  }
  sort(data.begin(), data.end());
  int ret = 1 << 30;
  for(int i = N - 1; i >= 0; i--) {
    ret = min(ret, rec(i) + N - i - 1);
  }
  cout << ret << endl;
}