#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;


int main() {
  int N, M, P[200000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> P[i];
    if(P[i] < M) P[i] = -1;
    else if(P[i] == M) P[i] = 0;
    else P[i] = 1;
  }
  vector< int > mp[402020];
  int sum = 202020, zerolast = -5;
  mp[sum].emplace_back(-1);
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    sum += P[i];
    if(P[i] == 0) zerolast = i;
    int add = 0;
    add += lower_bound(begin(mp[sum]), end(mp[sum]), zerolast) - begin(mp[sum]);
    add += lower_bound(begin(mp[sum - 1]), end(mp[sum - 1]), zerolast) - begin(mp[sum - 1]);
    ret += add;
    mp[sum].emplace_back(i);
  }
  cout << ret << endl;
}