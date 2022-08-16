#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M, S;
  int64 T;
  int64 pv[100001];
  memset(pv, -1, sizeof(pv));

  cin >> N >> M >> S >> T;
  --S;

  auto add = [&]() {
    if(S < M) {
      S += T % N;
      if(S >= N) S -= N;
    } else {
      S += N - T % N;
      if(S >= N) S -= N;
    }
  };

  for(;;) {

    if(~pv[S]) T %= pv[S] - T;
    pv[S] = T;
    if(T <= 202020) {
      while(T) add(), --T;
      cout << S + 1 << endl;
      return 0;
    }
    for(int i = 0; i < N; i++) {
      add();
      T--;
    }
  }
}