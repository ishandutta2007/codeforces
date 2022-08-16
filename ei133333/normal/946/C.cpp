#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  string S;
  cin >> S;

  char ptr = 'a';
  for(int i = 0; i < S.size() && ptr <= 'z'; i++) {
    if(S[i] <= ptr) {
      S[i] = ptr;
      ++ptr;
    }
  }

  if(ptr > 'z') cout << S << endl;
  else cout << -1 << endl;
}