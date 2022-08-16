#include<bits/stdc++.h>

using namespace std;


typedef long long int64;
const int64 INF = 1LL << 59;

int main()
{
  int64 T_S, T_F, t;
  int N;
  int64 S[100001];

  cin >> T_S >> T_F >> t;
  cin >> N;

  queue< int > que;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    que.emplace(i);
  }
  S[N] = INF;
  que.emplace(N);

  int64 now_time = T_S;
  int64 wait = INF;
  int64 time;
  while(!que.empty() && now_time + t <= T_F) {
    auto idx = que.front();
    if(now_time < S[idx]) {
      cout << now_time << endl;
      return (0);
    }
    if(now_time - S[idx] < wait) {
      wait = now_time - S[idx];
      time = S[idx] - 1;
    }
    now_time += t;
    que.pop();
  }

  cout << time << endl;
}