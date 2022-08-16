#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int N, A[300000];
vector< int > g[300000];
int64 ask, beet;

int64 rec(int idx, int par) {
  int64 ret = A[idx];
  for(auto &to : g[idx]) {
    if(to == par) continue;
    ret += max(0LL, rec(to, idx));
  }
  ask = max(ask, ret);
  return ret;
}

int64 rec2(int idx, int par) {
  int64 ret = A[idx];
  for(auto& to : g[idx]) {
    if(to == par) continue;
    ret += max(0LL, rec2(to, idx));
  }
  if(ret == ask) {
    ++beet;
    ret = 0;
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  bool f = false;
  int small = -INF;
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    f |= A[i] > 0;
    small = max(small, A[i]);
  }
  for(int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }


  if(!f) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
      sum += A[i] == small;
    }
    cout << 1LL*small*sum << " " << sum << endl;
    return 0;
  }

  rec(0, -1);
  assert(ask > 0);

  rec2(0, -1);
  cout << 1LL*ask*beet << " " << beet << endl;
}