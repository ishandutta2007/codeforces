#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 61;

int main()
{
  int N, L;
  int64 C[33];
  fill_n(C, 33, INF);

  cin >> N >> L;
  for(int i = 0; i < N; i++) {
    cin >> C[i];
  }

  for(int i = 31; i >= 0; i--) {
    C[i] = min(C[i], C[i + 1]);
  }
  for(int i = 1; i < 33; i++) {
    C[i] = min(C[i], C[i - 1] + C[i - 1]);
  }

  int64 sum = 0, ret = INF;
  for(int i = 31; i >= 0; i--) {
    if((L >> i) & 1) {
      ret = min(ret, sum + C[i + 1]);
      sum += C[i];
    }
  }

  cout << min(sum, ret) << endl;
}