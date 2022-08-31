#include <bits/stdc++.h>

using namespace std;


int main()
{
  string S;
  cin >> S;

  int ret = 114514;
  for(int i = 0; i < 1000000; i++) {
    string T = to_string(i);
    while(T.size() < 6) T = "0" + T;
    int latte = 0, malta = 0;
    for(int j = 0; j < 3; j++) latte += T[j] - '0';
    for(int j = 0; j < 3; j++) malta += T[j + 3] - '0';
    if(latte == malta) {
      int diff = 0;
      for(int j = 0; j < 6; j++) diff += S[j] != T[j];
      ret = min(ret, diff);
    }
  }
  cout << ret << endl;
}