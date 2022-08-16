#include <bits/stdc++.h>

using namespace std;


int main()
{
  string S;
  cin >> S;

  int num = 'a';
  bool killed[500] = {};
  for(int i = 0; i < S.size(); i++) {
    if(killed[i]) {
      continue;
    }
    if(S[i] != num) {
      cout << "NO" << endl;
      return (0);
    }
    for(int j = i; j < S.size(); j++) {
      if(num == S[j]) {
        killed[j] = true;
      }
    }
    ++num;
  }

  cout << "YES" << endl;
}