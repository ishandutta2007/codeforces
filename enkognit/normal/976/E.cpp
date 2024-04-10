#include <bits/stdc++.h>
#define fr front
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define pu push
#define pll pair<ll,ll>
#define len length()

using namespace std;

ll n,m,k,i,j,l,r,h,b[200001],u;
//string s;
bool tt;
pll a[200001];

bool comp(ll x,ll y)
{
 return ((a[x].fi-a[x].se>a[y].fi-a[y].se)||((a[x].fi-a[x].se==a[y].fi-a[y].se)&&(x<y)));
}

int main()
{
 cin >> n >> u >> k;
 m=1<<u;k=min(n,k);
 for (i=0;i<n;i++)
 {
  cin >> a[i].fi >> a[i].se;
  b[i]=i;
 }
 sort(b,b+n,comp);
 for (i=0;i<n;i++)
 {
  j=b[i];
  if (i<k) l+=max(a[j].fi,a[j].se); else l+=a[j].se;
 }
 //cout << l;
 r=l;
 if (k==0) {cout << l;exit(0);}
 for (i=0;i<n;i++)
 {
  j=b[i];
  if (i<k) l=max(l,r+a[j].fi*m-max(a[j].fi,a[j].se)); else
  l=max(l,r+a[j].fi*m-a[j].se-max(a[b[k-1]].fi,a[b[k-1]].se)+a[b[k-1]].se);
 }
 cout << l << "\n";
 //for (i=0;i<n;i++) cout << b[i] << "\n";
 return 0;
}