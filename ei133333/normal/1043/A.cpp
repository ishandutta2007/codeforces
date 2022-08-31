#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;

  cin >> N;
  int large = 0, sum = 0;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    large = max(large, x);
    sum += x;
  }
  for(int k = large;; k++) {
    int all = k * N;
    if(all - sum > sum) {
      cout << k << endl;
      return 0;
    }
  }


}