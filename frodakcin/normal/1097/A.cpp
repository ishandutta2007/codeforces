#include <iostream>
#include <cstdio>

using namespace std;

string t, c;

int main() {
  cin >> t;
  
  for(int i = 0;i < 5;i++) {
    cin >> c;
    if(t[0] == c[0] or t[1] == c[1]) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  
  return 0;
}