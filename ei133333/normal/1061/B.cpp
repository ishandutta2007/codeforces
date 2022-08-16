#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M, A[100000];
  cin >> N >> M;
  vector< int > mp;
  M = 0;
  int64 all = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    all += A[i];
    mp.emplace_back(A[i]);
    M = max(M, A[i]);
  }
  sort(begin(mp), end(mp));
  int64 ret = 0, used = 0;
  for(int i = 0; i < N; i++) {
    if(mp[i] > used) {
      ++ret;
      ++used;
    }
  }
  int64 rest1 = N - ret;
  int64 rest2 = M - ret;
  ret += rest1;
  ret += rest2;
  cout << all-ret << endl;
}