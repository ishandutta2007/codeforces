#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 mod = 1e9 + 7;

int main() {
  int N, Q;
  string S;

  cin >> N >> Q;
  cin >> S;
  vector< int > sum(N + 1);
  for(int i = 0; i < N; i++) sum[i + 1] = S[i] - '0';
  for(int i = 1; i <= N; i++) sum[i] += sum[i - 1];

  int64 po[100001];
  po[0] = 1;
  for(int i = 1; i < 100001; i++) po[i] = po[i - 1] * 2 % mod;

  while(Q--) {
    int L, R;
    cin >> L >> R;
    --L;
    int length = R - L;
    int one_length = sum[R] - sum[L];
    cout << (po[length] + mod - po[length - one_length]) % mod << endl;
  }
}