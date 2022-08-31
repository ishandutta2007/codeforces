#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int V[7], sum = 0;
    int64 K;
    cin >> K;
    for(int i = 0; i < 7; i++) {
      cin >> V[i];
      sum += V[i];
    }


    int64 ret = INF;
    for(int i = 0; i < 7; i++) {
      if(V[i] == 1) {
        int64 need = (K - 1) / sum;
        int64 add = need * 7;
        int64 rest = K - need * sum;
        int curr = i;

        while(rest > 0) {
          rest -= V[curr];
          ++add;
          (curr += 1) %= 7;
        }
        ret = min(ret, add);
      }
    }
    cout << ret << endl;
  }
}