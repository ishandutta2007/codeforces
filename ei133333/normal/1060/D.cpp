#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;


int main() {
  int N;
  cin >> N;
  vector< int > L(N), R(N);
  for(int i = 0; i < N; i++) cin >> L[i] >> R[i];
  sort(begin(L), end(L));
  sort(begin(R), end(R));
  int64 ret = N;
  for(int i = 0; i < N; i++) ret += max(L[i], R[i]);
  cout << ret << endl;
}