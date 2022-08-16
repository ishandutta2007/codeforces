#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[200000];
  cin >> N;
  int64 all = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    all += A[i];
  }
  int64 sub = 0;
  for(int i = 0; i < N; i++) {
    sub += A[i];
    if(sub * 2 >= all) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}