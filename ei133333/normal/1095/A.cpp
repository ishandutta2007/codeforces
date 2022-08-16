#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  string T;
  cin >> T;
  for(int i = 0, j = 1; i < N; i += j, j++) {
    cout << T[i];
  }
  cout << endl;
}