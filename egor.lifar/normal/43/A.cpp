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
  scanf("%d", &n);
  string s;
  string s2;
  int k = 0, k2 = 0;
  string a[1000];
  for(int i =0; i<n; i++){
    cin >> a[i];
    s = a[0];
    if(a[i] == s){
      k++;
    } else {
      s2 = a[i];
      k2++;
    }
  }
  if(k > k2){
    cout << s;
  } else {
    cout << s2;
  }
  return 0;
}