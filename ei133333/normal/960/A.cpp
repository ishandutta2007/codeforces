#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  string S;
  cin >> S;

  int state = 0;
  int a = 0, b = 0, c = 0;
  for(int i = 0; i < S.size(); i++) {
    if(state == 0) {
      if(S[i] == 'b') {
        state = 1;
      } else if(S[i] == 'a') {
        ++a;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
    if(state == 1) {
      if(S[i] == 'c') {
        state = 2;
      } else if(S[i] == 'b') {
        ++b;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
    if(state == 2) {
      if(S[i] == 'c') {
        ++c;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }

  }

  if(a == 0 || b == 0) {
    cout << "NO" << endl;
    return 0;
  }
  
  if(a == c || b == c) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}