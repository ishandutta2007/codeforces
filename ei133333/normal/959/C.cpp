#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  if(N <= 5) {
    cout << -1 << endl;
  } else {
    for(int i = 0; i + 6 < N; i++) {
      cout << i + 1 << " " << i + 2 << endl;
    }
    int base = N - 5;
    cout << base << " " << base + 1 << endl;
    cout << base << " " << base + 2 << endl;
    cout << base << " " << base + 3 << endl;
    cout << base + 3 << " " << base + 4 << endl;
    cout << base + 3 << " " << base + 5 << endl;
  }

  for(int i = 1; i < N; i++) {
    cout << i << " " << i + 1 << endl;
  }
}