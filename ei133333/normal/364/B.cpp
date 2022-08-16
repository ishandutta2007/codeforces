#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int N, D, C[50];
bool dp[500001];

int main()
{
  cin >> N >> D;
  for(int i = 0; i < N; i++) {
    cin >> C[i];
  }

  dp[0] = true;
  for(int i = 0; i < N; i++) {
    for(int j = 500000; j >= C[i]; j--) {
      dp[j] |= dp[j - C[i]];
    }
  }

  int curr = 0, ret = 0;
  bool update = true;
  while(update) {
    update = false;
    for(int i = min(500000, curr + D); i > curr; i--) {
      if(dp[i]) {
        curr = i;
        update = true;
        ++ret;
        break;
      }
    }
  }


  cout << curr << " " << ret << endl;
}