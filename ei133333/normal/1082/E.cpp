#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int main() {
  int N, C, A[500000];
  scanf("%d %d", &N, &C);
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  map< int, vector< int > > appear;
  vector< int64 > Csum(N + 1);
  for(int i = 0; i < N; i++) {
    appear[A[i]].push_back(i);
    Csum[i + 1] = Csum[i] + (A[i] == C);
  }


  int64 ret = Csum[N];

  for(auto &p : appear) {
    auto &vs = p.second;
    vector< int64 > tap(vs.size());
    for(int i = 0; i < vs.size(); i++) tap[i] = i - Csum[vs[i] + 1];
    for(int i = (int)vs.size() - 2; i >= 0; i--) tap[i] = max(tap[i], tap[i + 1]);
    for(int i = 0; i < vs.size(); i++) {
      int64 add = Csum[vs[i]] - i + 1 + Csum[N];
      int64 uku = tap[i];
      ret = max(ret, uku + add);
    }
  }

  cout << ret << endl;
}