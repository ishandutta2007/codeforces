#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, K;
    cin >> N >> K;
    string s;
    for(int i = 0; i < N; i++) {
      s += (char) ('a' + (i % K));
    }
    cout << s << endl;
  }
}