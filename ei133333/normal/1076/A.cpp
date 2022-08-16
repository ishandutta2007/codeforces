#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  for(int i = 0; i + 1 < S.size(); i++) {
    if(S[i] > S[i + 1]) {
      cout << S.substr(0, i) << S.substr(i + 1) << endl;
      return 0;
    }
  }
  cout << S.substr(0, N - 1) << endl;
}