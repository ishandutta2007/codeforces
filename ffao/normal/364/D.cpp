#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <time.h>

using namespace std;

int n;
long long a[1000000];

long long gcd(long long a, long long b) {
   if (!b) return a;
   return gcd(b, a%b);
}

int main() {
   srand(5886);

   clock_t start = clock();
   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      scanf("%I64d", &a[i]);
   }

   long long ans = 1;
   while (clock()-start < 3.5*CLOCKS_PER_SEC) {
      int idx = ((rand() << 15) + rand())%n;
      
      vector<long long> d;
      map<long long, int> cnt;

      long long num = a[idx];
      for (long long i = 1; i*i <= num; i++) {
         if (num % i == 0) {
            d.push_back(i);
            if (num / i != i) d.push_back(num/i);
         }
      }

      for (int i = 0; i < n; i++) {
         cnt[gcd(a[i], a[idx])]++;
      }

      
      sort(d.begin(), d.end());
      for (int i = 0; i < d.size(); i++) {
         for (int j = 0; j < i; j++) {
            if (d[i] % d[j] == 0) cnt[d[j]] += cnt[d[i]]; 
         }
      }

      for (int i = 0; i < d.size(); i++) {
         if (cnt[d[i]] >= (n+1)/2) ans = max(ans, d[i]);
      }
   }

   printf("%I64d\n", ans);
}