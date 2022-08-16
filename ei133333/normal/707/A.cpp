#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  bool other = false;
  while(N--) {
    for(int i = 0; i < M; i++) {
      char c;
      cin >> c;
      other |= (c != 'W' && c != 'B' && c != 'G');
    }
  }
  if(other) cout << "#Color" << endl;
  else cout << "#Black&White" << endl;
}