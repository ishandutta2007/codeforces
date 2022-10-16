#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <ctype.h>

using namespace std;

char num[4100];
int a;

long long poss[37000];

int sum[4100];

int main() {
   scanf("%d", &a);
   scanf("%s", num);

   int n = strlen(num);
   for (int i = 0; i < n; i++) {
      int tot = 0;
      for (int j = i; j < n; j++) {
         tot += num[j]-'0';
         poss[tot]++;
      }
   }

   long long ans = 0;
   if (a == 0) {
      ans += poss[0]*poss[0];
   }

   for (int i = 1; i <= 9*n; i++) {
      if (a % i == 0 && a/i <= i) {
         long long inc = poss[i]*poss[a/i];
         if (a / i != i) 
            inc *= 2;
         ans += inc;
      }
   }

   cout << ans << endl;
}