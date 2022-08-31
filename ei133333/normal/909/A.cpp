#include <bits/stdc++.h>

using namespace std;


int main()
{
  string S, T;
  cin >> S >> T;
  string ret = "~";
  for(int i = 1; i <= S.size(); i++) {
    for(int j = 1; j <= T.size(); j++) {
      ret = min(ret, S.substr(0, i) + T.substr(0, j));
    }
  }
  cout << ret << endl;
}