#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m,i,j,l=1e9,r,o,k=0;ll x,y,b[1001],a[1001];
string s;

int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> b[i];
   a[b[i]]++;
  }
  k=0;
  for (i=0;i<n;i++)
  if (a[b[i]]==1) l++; else if (a[b[i]]>2)k=1;
  if (l%2)
   if (!k) {cout << "NO";exit(0);}
  cout << "YES\n";
  k=0;
  for (i=0;i<n;i++)
  {
   if (a[b[i]]==1)
   {
    if (k%2) s+='B'; else s+='A';
    k++;
   }else
   if (a[b[i]]==2)
   {
    s+='B';a[b[i]]=-1;
   }else
   if (a[b[i]]==-1) s+='A';else
   if (l%2)s+='B',l--;else s+='A';
  }
  cout << s;
  return 0;
}
/**/