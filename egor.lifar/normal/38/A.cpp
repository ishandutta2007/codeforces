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
  // int n;
  // string s;
  // cin >> s;
  // int n2 = s.size();
  // sort(s.begin(), s.end());
  // vector <pair <int, char> > b(1000);
  // int c = 0;
  // int j =0;
  // for(int i =0; i<n2; i++) {
  //   if(i > 0 && s[i] = s[i-1] || i == 0 ){
  //     c++;
  //   } else {
  //     b[j].first = c;
  //     b[j].second = s[i - 1];
  //     c = 1;
  //     j++;
  //   }
  // }
  // b[j].first = c;
  // b[j].second = a[n2 - 1];
  // if(n < j){
  //   printf("-1");
  //   return 0;
  // }
  int n;
  int a[100], b, c;
  scanf("%d", &n);
  for(int i =1; i<n; i++){
    cin >> a[i];
  }
  cin >> b >> c;
  int s = 0;
  for(int i = b; i < c; i++){
    s += a[i];
  }
  cout << s;
  return 0;
}