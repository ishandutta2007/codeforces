#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>


using namespace std;


int n, k;
int a[1000];
int l, p = 1000000;


int main() {
   cin >> n >> k;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   for (int i = 1; i <= 1000; i++) {
      int s = 0;
      for (int j = 0; j < n; j++) {
         if (a[j] != i + j * k) {
            s++;
         }
      }
      if (s < p) {
         p = s;
         l = i;
      }
   }
   cout << p << endl;
   for (int i = 0; i < n; i++) {
      if (a[i] != l + i * k) {
         if (a[i] < l + i * k) {
            cout << '+' << ' ' << i + 1 << ' ' << l + i * k - a[i] << endl;
         } else {
            cout << '-' << ' ' << i + 1 << ' ' << a[i] - l - i * k  << endl;
         }
      }
   }
   return 0;
}