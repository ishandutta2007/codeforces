#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   int month, day;
   cin >> month >> day;

   if (month == 4 || month == 6 || month == 9 || month == 11) {
      // 30 days
      cout << 1 + (30+day-2)/7 << endl;
   }
   else if (month == 2) {
      // 28 days
      cout << 1 + (28+day-2)/7 << endl;
   }
   else {
      // 31 days
      cout << 1 + (31+day-2)/7 << endl;
   }

   return 0;
}