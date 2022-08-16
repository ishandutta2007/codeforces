#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 59;

int N, M, K, D[100000], F[100000], T[100000], C[100000];
vector< pair< int, int > > in[1000005], out[1000005];
int64 dp1[1000005], dp2[1000005], member[100005];

int main()
{
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 0; i < M; i++) {
    scanf("%d %d %d %d", &D[i], &F[i], &T[i], &C[i]);
    if(T[i] == 0) in[D[i]].emplace_back(F[i], C[i]);
    else out[D[i]].emplace_back(T[i], C[i]);
  }

  {
    int64 rest = N, cost = 0;
    fill_n(dp1, 1000005, INF);
    fill_n(member, 100005, INF);
    for(int i = 0; i < 1000005; i++) { // begin date
      if(rest == 0) {
        dp1[i] = cost;
      }

      for(auto &s : in[i]) {
        if(member[s.first] == INF) {
          --rest;
          member[s.first] = s.second;
          cost += s.second;
        } else if(s.second < member[s.first]) {
          cost -= member[s.first];
          member[s.first] = s.second;
          cost += member[s.first];
        }
      }
    }
  }

  {
    int64 rest = N, cost = 0;
    fill_n(dp2, 1000005, INF);
    fill_n(member, 100005, INF);
    for(int i = 1000004; i >= 0; i--) {
      if(rest == 0) dp2[i] = cost;

      for(auto &s : out[i]) {
        if(member[s.first] == INF) {
          --rest;
          member[s.first] = s.second;
          cost += s.second;
        } else if(s.second < member[s.first]) {
          cost -= member[s.first];
          member[s.first] = s.second;
          cost += member[s.first];
        }
      }
    }
  }

  int64 ret = INF;
  for(int i = 0; i < 1000005; i++) {
    if(i + K - 1 >= 1000005) continue;
    ret = min(ret, dp1[i] + dp2[i + K - 1]);
  }

  if(ret == INF) ret = -1;
  printf("%lld\n", ret);
}