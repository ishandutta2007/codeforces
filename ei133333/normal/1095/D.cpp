#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


int main() {
  int N, X[200000], Y[200000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    --X[i], --Y[i];
  }
  for(int i = 0; i < 2; i++) {
    swap(X[0], Y[0]);

    vector< int > ans(N, -1);
    ans[0] = 0;
    ans[1] = X[0];
    ans[2] = Y[0];

    bool correct = true;
    for(int _ = 1; _ < N; _++) {
      int j = ans[_];
      bool cor = false;
      for(int k = 0; k < 2; k++) {
        swap(X[j], Y[j]);
        if((ans[(_ + 1) % N] == X[j] || ans[(_ + 1) % N] == -1) &&
           (ans[(_ + 2) % N] == Y[j] || ans[(_ + 2) % N] == -1)) {
          ans[(_ + 1) % N] = X[j];
          ans[(_ + 2) % N] = Y[j];
          cor = true;
          break;
        }
      }
      correct &= cor;
    }
    if(correct) {
      for(auto &p : ans) cout << p + 1 << " ";
      cout << endl;
      return 0;
    }
  }

}