#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  string S, T[100];

  cin >> S;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      string Q = T[i] + T[j];
      if(Q.find(S) != string::npos) {
        cout << "YES" << endl;
        return (0);
      }
    }
  }

  cout << "NO" << endl;
}