

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;




int main() {
  int n;
  char s[100];
  scanf("%d", &n);
  scanf("%s", &s);
  int k = 0;
  for(int i = 1; i<n; i++) {
    if(s[i] == s[i-1]) {
      k++;
    }
  }
  printf("%d", k);


}