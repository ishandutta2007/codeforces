#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector< int > V, A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    V.emplace_back(A[i] - 1);
    V.emplace_back(A[i]);
    V.emplace_back(A[i] + 1);
  }
  sort(begin(V), end(V));
  V.erase(unique(begin(V), end(V)), end(V));
  vector< int > f(V.size());
  for(int i = 0; i < N; i++) {
    A[i] = lower_bound(begin(V), end(V), A[i]) - begin(V);
    f[A[i]] = true;
  }

  int pre = -1;
  vector< pair< int, int > > lis;  int64 add = 0;

  for(int i = 0; i < V.size(); i++) {
    if(!f[i] && ~pre) {
      lis.emplace_back(V[pre], V[i]);
      add += V[i] - V[pre];
      pre = -1;
    } else if(f[i] && pre == -1) {
      pre = i;
    }
  }
  vector< int > pend;
  for(int i = 1; i < lis.size(); i++) {
    pend.emplace_back(lis[i].first - lis[i - 1].second);
  }
  sort(begin(pend), end(pend));
  reverse(begin(pend), end(pend));
  while(lis.size() > K) {
    lis.pop_back();
    add += pend.back();
    pend.pop_back();
  }
  cout << add << endl;
}