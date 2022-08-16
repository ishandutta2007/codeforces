#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 mod = 1e9 + 7;


int main() {
  int N, M;

  cin >> N >> M;
  vector< int64 > A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A.rbegin(), A.rend());

  auto check = [&](int days) {
    int64 page = 0;
    for(int i = 0; i < N; i++) {
      page += A[i] - i / days;
      if(page >= M) return true;
    }
    return false;
  };

  int ok = N + 1, ng = 0;
  while(ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  if(ok == N + 1) cout << -1 << endl;
  else cout << ok << endl;
}