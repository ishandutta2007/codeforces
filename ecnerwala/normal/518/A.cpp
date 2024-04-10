#include<bits/stdc++.h>

using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  for(int i = s.size() - 1; true; i--){
    s[i] ++;
    if(s[i] > 'z') {
      s[i] = 'a';
    }
    else break;
  }
  if(s==t) {
    s = "No such string";
  }
  cout << s << '\n';
}