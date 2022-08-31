#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using Mat = vector< string >;
const int64 INF = 1LL << 60;

int main() {
  int N;
  cin >> N;
  Mat a[4];
  for(int i = 0; i < 4; i++) {
    a[i].resize(N);
    for(int j = 0; j < N; j++) {
      cin >> a[i][j];
      for(int k = 0; k < N; k++) {
        a[i][j][k] -= '0';
      }
    }
  }

  vector< int > order{0, 1, 2, 3};
  int64 ret = INF;
  do {
    int64 latte = 0, malta = 0;
    for(int i = 0; i < 2 * N; i++) {
      for(int j = 0; j < 2 * N; j++) {
        if(i < N && j < N) {
          if((i + j) & 1) latte += a[order[0]][i][j];
          else latte += 1 - a[order[0]][i][j];
          if((i + j) & 1) malta += 1 - a[order[0]][i][j];
          else malta += a[order[0]][i][j];
        } else if(i < N) {
          if((i + j) & 1) latte += a[order[1]][i][j - N];
          else latte += 1 - a[order[1]][i][j - N];
          if((i + j) & 1) malta += 1 - a[order[1]][i][j - N];
          else malta += a[order[1]][i][j - N];
        } else if(j < N) {
          if((i + j) & 1) latte += a[order[2]][i - N][j];
          else latte += 1 - a[order[2]][i - N][j];
          if((i + j) & 1) malta += 1 - a[order[2]][i - N][j];
          else malta += a[order[2]][i - N][j];
        } else {
          if((i + j) & 1) latte += a[order[3]][i - N][j - N];
          else latte += 1 - a[order[3]][i - N][j - N];
          if((i + j) & 1) malta += 1 - a[order[3]][i - N][j - N];
          else malta += a[order[3]][i - N][j - N];
        }
      }
    }
    ret = min(ret, latte);
    ret = min(ret, malta);
  } while(next_permutation(begin(order), end(order)));
  cout << ret << endl;
}