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
  // scanf("%d", &n);
  // int n2 = s.size();
  // sort(s.begin(), s.end());
  // vector <pair <int, char> > b(1000);
  // int c = 0;
  // int j =0;
  // for(int i =0; i<n2; i++) {
  //   if((i > 0 && s[i] == s[i-1]) || i == 0 ){
  //     c++;
  //   } else {
  //     b[j].first = c;
  //     b[j].second = s[i - 1];
  //     c = 1;
  //     j++;
  //   }
  // }
  // b[j].first = c;
  // b[j].second = s[n2 - 1];
  // if(n < j + 1){
  //   printf("-1");
  //   return 0;
  // }
  // int s3 = 0;
  // int x = 0;
  // while(s3 > n || x == 0) {
  //    x++;
  //    int s3 = 0;
  //    for(int i =0; i<=j; i++){
  //      s3 += (b[i].first + x - 1) / x;
  //    }
  // }
  // printf("%d\n", x);
  // if(s3 < n){
  //   for(int i =0; i<n - s3 - 1; i++){
  //     cout << s[0];
  //   }
  // }
  // for(int i =0; i<=j; i++){
  //    for(int g = 0; g<(b[i].first + x - 1) / x; g++){
  //     printf("%c", b[i].second);
  //    }
  // }
  int n;
  string s[1000], s2[1000];
  scanf("%d", &n);
  s2[0]= "ABSINTH";
  s2[1]= "BEER";
  s2[2]= "BRANDY";
  s2[3]= "CHAMPAGNE";
  s2[4]= "GIN";
  s2[5]= "RUM";
  s2[6]= "SAKE";
  s2[7]= "TEQUILA";
  s2[8]= "VODKA";
  s2[9]= "WHISKEY";
  s2[10]= "WINE";
  for(int i =0;i<n; i++){
    cin >> s[i];
  }
  int k = 0;
  for(int i =0;i<n; i++){
    if(s[i][0] >='0' && s[i][0] <= '9'){
       int p = s[i].size();
       int t = 1;
       int r  = 0;
       for(int j = p-1; j>=0; j--){
          r += (s[i][j] - '0') * t;
          t *= 10;
       }
       if(r < 18){
        k++;
       }
    }else{
       for(int j =0; j<11; j++){
        if(s[i] == s2[j]){
          k++;
          break;
        }
       }
    }
  }
  printf("%d\n", k);
  return 0;
}