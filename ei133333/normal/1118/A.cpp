#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 mod = 1e9 + 7;


int main() {
  int Q;
  cin >> Q;
  while(Q--) {
    int64 N, A, B;
    cin >> N >> A >> B;
    if(A * 2 <= B) {
      cout << A * N << endl;
    } else {
      cout << N / 2 * B + N % 2 * A << endl;
    }
  }
}