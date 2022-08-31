#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

string poyo = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_";

int main()
{

  int lookup[64] = {};
  for(int i = 0; i < 64; i++) {
    for(int j = 0; j < 64; j++) {
      for(int k = 0; k < 64; k++) {
        if((j & k) == i) lookup[i]++;
      }
    }
  }
  
  string s;
  cin >> s;

  int ret = 1;
  for(int i = 0; i < s.size(); i++) {
    ret = (1LL * ret * lookup[poyo.find(s[i])]) % mod;
  }
  cout << ret << endl;
}