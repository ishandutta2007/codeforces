#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
long long best[160000][2];
int n,m,d;
int a, b;
long long t;

pair<long long, int> st[160000];
int ini, fim;

int main() {
   scanf("%d %d %d", &n, &m, &d);

   int curr = 0;
   long long sum = 0;
   long long lt = 1;

   for (int q = 0; q < m; q++) {
      scanf("%d %d %I64d", &a, &b, &t);
      a--;
      sum += b;

      ini=fim=0;
      for (int i = 0; i < n; i++) {
         while (ini != fim && i - st[ini].second > d*(t-lt) ) ini++;
         while (ini != fim && st[fim-1].first <= best[i][curr]) fim--;
         st[fim++] = make_pair(best[i][curr], i);
      
         best[i][curr^1] = st[ini].first - abs(a - i);
      }

      ini=fim=0;
      for (int i = n-1; i >= 0; i--) {
         while (ini != fim && st[ini].second - i > d*(t-lt) ) ini++;
         while (ini != fim && st[fim-1].first <= best[i][curr]) fim--;
         st[fim++] = make_pair(best[i][curr], i);
      
         best[i][curr^1] = max(best[i][curr^1], st[ini].first - abs(a - i));
      }

      curr ^= 1;
      lt = t;
   }

   long long top = best[0][curr];
   for (int i = 0; i < n; i++) {
      top = max(top, best[i][curr]);
   }

   printf("%I64d\n", top + sum);
}