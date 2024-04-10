#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 
using namespace std;


int a[200000];
int d[200000], d1[200000];


int main() {
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   } 
   for (int i = 0; i < n; i++) {
      if (i > 0) {
         d[i] = d[i - 1];
      }
      if (i > 0) {
         d1[i] = d1[i - 1];
      }
      if (a[i] == 0){
         d[i]++;
      }
      if (a[i] == 1){
         d1[i]++;
      }
   } 
   long long s = 0;
   long long s1 = 0;
   for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 1) {
         s += d[n - 1];
         if (i > 0) {
            s -= d[i - 1];
         }
      }
   }
   for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
         s1 += i > 0 ? d1[i - 1]: 0;
      }
   }
   cout << min(s, s1) << endl;
	return 0;
}