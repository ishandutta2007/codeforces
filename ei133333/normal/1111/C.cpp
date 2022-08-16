#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int64 N, K, A, B;
vector< int > P;
map< pair< int, int >, int64 > mp;

int64 rec(int l, int r) {
  if(mp.count({l, r})) return mp[{l, r}];
  int sz = lower_bound(begin(P), end(P), r) - lower_bound(begin(P), end(P), l);
  if(sz == 0) return mp[{l,r}] = A;
  int64 ret = B * sz * (r - l);
  if(r - l >= 2) ret = min(ret, rec(l, (l + r) / 2) + rec((l + r) / 2, r));
  return mp[{l, r}] = ret;
}



int main() {
  cin >> N >> K >> A >> B;
  for(int i = 0; i < K; i++) {
    int x;
    cin >> x;
    --x;
    P.emplace_back(x);
  }
  sort(begin(P), end(P));
  cout << rec(0, 1 << N) << endl;
}