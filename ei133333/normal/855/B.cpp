#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;

int64 N, P, Q, R, A[100000];
int64 LL[2][100000], RR[2][100000];

int main()
{
  cin >> N >> P >> Q >> R;
  for(int i = 0; i < N; i++) cin >> A[i];

  int64 latte = INF, malta = -INF;
  for(int i = N - 1; i >= 0; i--) {
    latte = min(latte, A[i]);
    malta = max(malta, A[i]);
    LL[0][i] = latte, LL[1][i] = malta;
  }
  latte = INF, malta = -INF;
  for(int i = 0; i < N; i++) {
    latte = min(latte, A[i]);
    malta = max(malta, A[i]);
    RR[0][i] = latte, RR[1][i] = malta;
  }

  int64 ret = numeric_limits< int64 >::min();
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        ret = max(ret, RR[j][i] * P + A[i] * Q + LL[k][i] * R);
      }
    }
  }

  cout << ret << endl;
}