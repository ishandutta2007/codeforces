#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  int bit[1 << 4] = {};

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    int s = 0;
    for(int j = 0; j < K; j++) {
      int p;
      cin >> p;
      s |= p << j;
    }
    bit[s]++;
  }

  if(bit[0] > 0) {
    cout << "YES" << endl;
    return(0);
  }

  for(int i = 0; i < (1 << K); i++) {
    if(bit[i] == 0) continue;
    bit[i]--;
    for(int j = 0; j < (1 << K); j++) {
      if(bit[j] == 0) continue;
      bit[j]--;

      bool flag = false;
      for(int k = 0; k < 4; k++) {
        if((i >> k) & 1 && (j >> k) & 1) flag = true;
      }

      if(!flag) {
        cout << "YES" << endl;
        return(0);
      }
      bit[j]++;
    }
    bit[i]++;
  }

  cout << "NO" << endl;
}