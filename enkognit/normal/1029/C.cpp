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

ll n,m,k,i,j,l,r,a[1000001],b[1000001];
ll t1,t2,tt,tl,tr,tll;

int main()
{
 cin >> n;
 ll r1=1e9,r2=1e9,l1=0,l2=0;
 for (i=0;i<n;i++)
 {
  cin >> a[i] >> b[i];ll x=a[i],y=b[i];
  if (x>l1) l2=l1,l1=x; else if (x>l2) l2=x;
  if (y<r1) r2=r1,r1=y; else if (y<r2) r2=y;
 }
 for (i=0;i<n;i++)
 {
  if (a[i]==l1 && b[i]==r1) k=max(k,r2-l2); else
  if (a[i]==l1) k=max(k,r1-l2); else
  if (b[i]==r1) k=max(k,r2-l1); else
  k=max(k,r1-l1);
 }
 cout << k;
 return 0;
}