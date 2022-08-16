#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;

  for(int i = 0; i < s.size(); i++) {
    if(s[i] != 'a') {
      for(int j = i; j < s.size(); j++) {
        if(s[j] == 'a') break;
        s[j]--;
      }
      cout << s << endl;
      return(0);
    }
  }

  s.back() = 'z';
  cout << s << endl;
}