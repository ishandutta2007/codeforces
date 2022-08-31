#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[1000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  int ret = 0;
  while(*max_element(A + 1, A + N) >= A[0]) {
    auto pos = max_element(A + 1, A + N) - A;
    --A[pos];
    ++A[0];
    ++ret;
  }
  cout << ret << endl;
}