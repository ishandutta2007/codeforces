#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  int N;
  int ret = 0;

  cin >> N;
  cin >> S;
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == '<') ++ret;
    else break;
  }
  for(int i = S.size() - 1; i >= 0; i--) {
    if(S[i] == '>') ++ret;
    else break;
  }
  cout << ret << endl;

}