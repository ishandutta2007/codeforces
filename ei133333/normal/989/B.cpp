#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, P;
  cin >> N >> P;
  string S;
  cin >> S;

  bool correct = false;
  for(int i = 0; i < N; i++) {
    if(i + P < N) {
      if(S[i] == '.') {
        if(S[i + P] == '.') S[i + P] = '1';
        S[i] = S[i + P] == '1' ? '0' : '1';
        correct = true;
      } else if(S[i + P] == '.') {
        S[i + P] = S[i] == '1' ? '0' : '1';
        correct = true;
      } else if(S[i] != S[i + P]) {
        correct = true;
      }
    }
    if(S[i] == '.') {
      S[i] = '0';
    }
  }

  if(!correct) {
    cout << "No" << endl;
  } else {
    cout << S << endl;
  }
}