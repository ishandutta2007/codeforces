#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N;
  cin >> N;
  if(N == 0) cout << 0 << endl;
  else if(N % 2 == 1) cout << N / 2 + 1 << endl;
  else cout << N + 1 << endl;
}