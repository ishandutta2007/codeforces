#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    string S;
    cin >> N;
    cin >> S;
    string T = S;
    reverse(begin(T), end(T));
    int ok = 0;
    for(int i = 0; i < N; i++) {
      if(abs(S[i] - T[i]) == 2 || S[i] == T[i]) ++ok;
    }
    if(ok == N) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}