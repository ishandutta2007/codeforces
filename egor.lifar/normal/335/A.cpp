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
  string s;
  cin >> s;
  scanf("%d", &n);
  int n2 = s.size();
  sort(s.begin(), s.end());
  vector <pair <int, char> > b(1000);
  int c = 0;
  int j =0;
  for(int i =0; i<n2; i++) {
    if((i > 0 && s[i] == s[i-1]) || i == 0 ){
      c++;
    } else {
      b[j].first = c;
      b[j].second = s[i - 1];
      c = 1;
      j++;
    }
  }
  b[j].first = c;
  b[j].second = s[n2 - 1];
  if(n < j + 1){
    printf("-1");
    return 0;
  }
  int s3 = 0;
  int x = 0;
  while(s3 > n || x == 0) {
     x++;
     s3 = 0;
     for(int i =0; i<=j; i++){
       s3 += (b[i].first + x - 1) / x;
     }
  }
  printf("%d\n", x);
  if(s3 < n){
    for(int i =0; i<n - s3; i++){
      cout << s[0];
    }
  }
  for(int i =0; i<=j; i++){
     for(int g = 0; g<(b[i].first + x - 1) / x; g++){
      printf("%c", b[i].second);
     }
  }
  
  return 0;
}