#include <bits/stdc++.h>
#define fr front
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define pint pair<int,int>
#define pu push
#define len length()

using namespace std;

ll a[100001],b[100001],n,m,i,j,k,l=-1,r=-1;
pint t[1000001];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n;
  for (i=1;i<=n;i++) {cin >> a[i];t[a[i]].fi++;t[a[i]-1].se++;}
  /*for (i=1;i<=n;i++)
  cout << t[a[i]].fi << " " << t[a[i]].se << "\n";*/
  for (i=1000000;i>=1;i--)
   if (t[i].fi+t[i].se>1)
  {
   while (t[i].se>1)
   {
    if (l!=-1)
    k+=l*i,l=-1; else l=i;
    t[i].se-=2;
   }
   if (t[i].se%2==1 && t[i].fi>0)
   {t[i].fi--,t[i-1].se--;if (l==-1) l=i; else k+=l*i,l=-1;}
   while (t[i].fi>1)
   {
    if (l!=-1)
    k+=l*i,l=-1; else l=i;
    t[i].fi-=2,t[i-1].se-=2;
   }
  }
  cout << k;
  return 0;
}