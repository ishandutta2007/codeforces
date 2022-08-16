#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  string S[1000];

  cin >> N;

  bool regist = false;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    if(!regist) {
      if(S[i][0] == 'O' && S[i][1] == 'O') {
        S[i][0] = S[i][1] = '+';
        regist = true;
      } else if(S[i][3] == 'O' && S[i][4] == 'O') {
        S[i][3] = S[i][4] = '+';
        regist = true;
      }
    }
  }
  if(!regist) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for(int i = 0; i < N; i++) {
      cout << S[i] << endl;
    }
  }
}