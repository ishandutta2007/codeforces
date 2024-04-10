#include <bits/stdc++.h>
#define fr front
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define pu push
#define len length()

using namespace std;

ll a[100001],b[100001],n,m,i,j,k,l,r;
pair<ll,ll> t[5001];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (i=1;i<=n;i++)
  {
   cin >> a[i] >> b[i];
   t[a[i]].fi+=b[i];
   t[a[i]+1].se+=b[i];
  }
  for (i=1;i<=3001;i++)
  {
   if (t[i].se>=m) k+=m; else
   {
    ll z=min(t[i].fi,m-t[i].se);
    t[i+1].se-=z;
    k+=min(t[i].se+t[i].fi,m);
   }
  }
  cout << k;
  return 0;
}