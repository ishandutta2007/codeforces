#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 INF = (1LL << 60) - 1;

pair< int64, int64 > dp[114514];

int64 N;
string K;

pair< bool, int64 > rec(const int idx)
{
  if(idx == K.size()) return (make_pair(true, 0));
  if(~dp[idx].first) return (dp[idx]);
  int64 ret = INF;
  int64 now = 0, base = 1;
  for(int64 i = idx; i < K.size() && base <= N; i++, base *= 10) {
    now = now + base * (K[i] - '0');
    if(now >= N) break;
    if(K[i] == '0' && idx != i) continue;
    auto pp = rec(i + 1);
    if(!pp.first) continue;
    if((pp.second * N) / N != pp.second) continue;
    if((pp.second * N) >= INF) continue;
    if(pp.second * N + now < 0) continue;
    ret = min(ret, pp.second * N + now);
  }
  if(ret == INF) return (dp[idx] = make_pair(false, -1));
  return (dp[idx] = make_pair(true, ret));
}

int main()
{
  fill_n(dp, 114514, make_pair(-1, -1));
  cin >> N;
  cin >> K;
  reverse(begin(K), end(K));
  if(!rec(0).first) throw (0);
  cout << rec(0).second << endl;
}