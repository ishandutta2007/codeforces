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



int k, a, b, v;
int k2;


int main() {
   cin >> k >> a >> b >> v;
   int ans = 0;
   int s = 0;
   while (s < a) {
      if (a - s < v) {
         s = a;
      } else {
         int k1 = 0;
         s += v;
         while (k1 + 1 < k && k2 + 1 <= b && s < a) {
            k1++;
            k2++;
            if (a - s < v) {
               s = a;
               break;
            }
            s += v;
         }
      }
      ans++;
   }
   cout << ans << endl;
   return 0;
}