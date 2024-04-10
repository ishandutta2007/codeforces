#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct entry{
 int a,idx;
} e[2005];
int comp(entry a, entry b) {
return a.a > b.a;
}
int n,ans[9999];
int main()
{
 cin>>n;
 for(int i= 0 ; i < n; ++i) {
  cin >> e[i].a;
  e[i].idx = i;
 }
 sort(e,e+n,comp);
 for (int i = 0; i < n; ++i) {
  if (i == 0 || e[i].a != e[i-1].a) 
   ans[e[i].idx] = i+1;
  else ans[e[i].idx] = ans[e[i-1].idx];
 }
 for (int i = 0; i < n; ++i) cout << ans[i]<<" ";
}