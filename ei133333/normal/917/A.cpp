#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;


int main()
{
  string s;
  cin >> s;

  int ret = 0;

  for(int i = 0; i < s.size(); i++) {
    int x = 0, y = 0;
    for(int j = i; j < s.size(); j++) {
      if(s[j] == '(') ++x, ++y;
      else if(s[j] == ')') --x, --y;
      else ++x, --y;
      if(y < 0) ++y;
      if(x < 0) break;
      if((j - i) % 2 == 1) {
        ret += y <= 0;
      }
    }
  }

  cout << ret << endl;
}