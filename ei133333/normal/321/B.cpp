#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;


int64 solve2(vector< multiset< int > > X, vector< int > Y) {
  int M = (int) Y.size();
  int64 add = 0;
  for(int i = M - 1; i >= 0; i--) {
    if(X[1].empty()) break;
    auto v = X[1].begin();
    if(*v > Y[i]) return add;
    add -= *v;
    add += Y[i];
    X[1].erase(v);
  }
  return add;
}


int64 solve1(vector< multiset< int > > X, vector< int > Y) {
  int M = (int) Y.size();
  bool used[100] = {};
  for(int i = 0; i < M; i++) {
    auto v = X[0].lower_bound(Y[i]);
    if(v == X[0].begin()) continue;
    --v;
    X[0].erase(v);
    used[i] = true;
  }
  if(X[0].size()) return -INF;
  int64 add = 0;
  for(int i = M - 1; i >= 0; i--) {
    if(X[1].empty()) break;
    if(used[i]) continue;
    auto v = prev(X[1].end());
    if(*v > Y[i]) return -INF;
    add -= *v;
    add += Y[i];
    used[i] = true;
    X[1].erase(v);
  }

  if(X[1].size()) return -INF;
  for(int i = M - 1; i >= 0; i--) {
    if(used[i]) continue;
    add += Y[i];
  }
  return add;
}


int main() {
  int N, M;
  cin >> N >> M;
  vector< multiset< int > > X(2);
  for(int i = 0; i < N; i++) {
    string s;
    int x;
    cin >> s >> x;
    X[s == "ATK"].emplace(x);
  }
  vector< int > Y(M);
  for(int i = 0; i < M; i++) {
    cin >> Y[i];
  }
  sort(begin(Y), end(Y));
  cout << max(solve1(X, Y), solve2(X, Y)) << endl;
}