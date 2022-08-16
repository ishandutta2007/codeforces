#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K, A[100];
  cin >> N >> K;
  int latte = 0, malta = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    latte += A[i] == 1;
    malta += A[i] == -1;
  }
  int ret = 0;
  for(int i = 0; i < K; i++) {
    int latte2 = latte, malta2 = malta;
    for(int j = i; j < N; j += K) {
      latte2 -= A[j] == 1;
      malta2 -= A[j] == -1;
    }
    ret = max(ret, abs(latte2 - malta2));
  }
  cout << ret << endl;
}