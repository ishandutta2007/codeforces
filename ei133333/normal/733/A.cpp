#include <bits/stdc++.h>

using namespace std;


int main()
{
  string S;
  cin >> S;
  S += "A";

  string T = "AEIOUY";
  int ret = 0, cnt = 0;
  for(int i = 0; i < S.size(); i++) {
    ++cnt;
    ret = max(ret, cnt);
    if(T.find(S[i]) != string::npos) cnt = 0;
  }
  cout << ret << endl;
}