#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e6+5;

int av[ms];

main() {
  string s;
  cin >> s;
  int i = 0;
  int j = s.size() - 1;
  while(i <= j) {
    if(s[i] == s[j]) {
      av[i] = 1;
      av[j] = 1;
      i++; j--;
    } else if(s[i+1] == s[j]) {
      av[++i] = 1;
      av[j] = 1;
      i++; j--;
    } else if(s[i] == s[j-1]) {
      av[i] = 1;
      av[--j] = 1;
      i++; j--;
    } else if(s[i+1] == s[j-1]) {
      av[++i] = 1;
      av[--j] = 1;
      i++; j--;
    }
  }
  for(int i = 0; i < s.size(); i++) {
    if(av[i]) cout << s[i];
  }
  cout << '\n';
}