#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  while(N--) {
    int64 K;
    int x;
    cin >> K >> x;
    // mod 9  x 
    cout << (K - 1) * 9 + x << endl;
  }
}