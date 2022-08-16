#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using Pi = pair< int64, int >;

int main() {
  int64 N, A[150000];
  cin >> N;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    que.emplace(A[i], i);
  }
  while(que.size() > 1) {
    auto p = que.top();
    que.pop();
    if(p.first == que.top().first) {
      auto q = que.top();
      que.pop();
      A[p.second] = -1;
      A[q.second] *= 2;
      que.emplace(A[q.second], q.second);
    }
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] != -1) ++ret;
  }
  cout << ret << endl;
  for(int i = 0; i < N; i++) {
    if(A[i] != -1) cout << A[i] << " ";
  }
  cout << endl;

}