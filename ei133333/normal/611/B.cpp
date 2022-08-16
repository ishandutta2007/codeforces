#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int64;
#define int unsigned long long

int64 strbin2i (string &s) {
  int64 out = 0;
  for (signed i = 0; i < s.size(); i++) {
    out *= 2ULL;
    out += (s[i] == '1') ? 1 : 0;
  }

  return out;
}

   
int get_value(int64 vale)
{
  int ret = 0;
  for(int i = 1; i <= 62; i++) {
    string s = string(i, '1');
    for(int j = 1; j < s.size(); j++) {
      s[j] = '0';
      ret += strbin2i(s) <= vale;
      s[j] = '1';
    }
  }
  return(ret);
}  

signed main(){  
  int64 a, b;
  cin >> a >> b;
  int64 aa = get_value(--a);
  int64 bb = get_value(b);
  cout << bb - aa << endl;
}