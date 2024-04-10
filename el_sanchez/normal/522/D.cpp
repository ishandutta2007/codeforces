#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <ctime>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1.);
typedef pair<int,int> pii;
#define X first
#define Y second
typedef vector<int> vi;


const int C = (int)5e5 + 19;
int a[C], b[C], fenw[C], ql[C], qr[C], qnext[C], fq[C], pval[C], psame[C], ans[C];


void upd(int i, int val)
{
  i++;
  for (; i > 0; i &= i-1) fenw[i] = min(fenw[i], val);
}

int getmin(int i)
{
  i++;
  int ans = (int)1e9;
  for (; i < C; i += -i & i) ans = min(ans, fenw[i]);
  return ans;
}


int main()
{
   int n, m;
   scanf("%d%d", &n, &m);

   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
     scanf("%d", &a[i]);
     b[cnt++] = a[i];
   }
   sort(b, b + cnt);
   cnt = unique(b, b + cnt) - b;
   for (int i = 0; i < n; i++) a[i] = lower_bound(b, b + cnt, a[i]) - b;

   for (int i = 0; i < C; i++) fenw[i] = (int)1e9;

   for (int i = 0; i < n; i++) fq[i] = -1;
   for (int i = 0; i < m; i++)
   {
      scanf("%d%d", &ql[i], &qr[i]);
      ql[i] --; qr[i] --;
      qnext[i] = fq[qr[i]];
      fq[qr[i]] = i; 
   } 
   for (int i = 0; i < n; i++) pval[i] = -1;
   for (int i = 0; i < n; i++)
   {
      psame[i] = pval[a[i]];
      pval[a[i]] = i;
   }
   for (int i = 0; i < m; i++) ans[i] = (int)1e9;
   for (int i = 0; i < n; i++)
   {
      upd(psame[i], i - psame[i]);
   //   cout << "i=" << i << endl;
      for (int j = fq[i]; j != -1; j = qnext[j])
      {
     //    cout << ql[j] << ' ' << qr[j] << endl; 
         ans[j] = min(ans[j],getmin(ql[j]));
      }
      
   }
   for (int i = 0; i < m; i++) printf("%d\n", ans[i]<(int)1e8?ans[i]:-1);
   return 0;
}