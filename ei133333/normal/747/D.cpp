#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K, T[200000];

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
    T[i] = T[i] >= 0;
  }

  vector< pair< int, int > > q;
  q.emplace_back(1, 0);
  for(int i = 0; i < N; i++) {
    if(q.back().first != T[i]) q.emplace_back(T[i], 0);
    ++q.back().second;
  }

  int ret = 0;
  vector< int > other;
  for(int i = 0; i < q.size(); i++) {
    if(!q[i].first) ret += q[i].second;
    else if(i > 0 && i + 1 < q.size()) other.emplace_back(q[i].second);
  }
  sort(begin(other), end(other));

  K -= ret;
  if(K < 0) {
    cout << -1 << endl;
    return (0);
  }

  int change = q.size() - 1;

  for(auto &cost : other) {
    if(K - cost >= 0) {
      change -= 2;
      K -= cost;
    }
  }

  if(q.size() > 1 && q.back().first && K - q.back().second >= 0) {
    change--;
    K -= q.front().second;
  }

  cout << change << endl;

}