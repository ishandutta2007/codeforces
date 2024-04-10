#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n,m,k,l,r,i,j,w,x,y,p,b[200001];
ll a[200001];
bool t;
string s,d;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  cin >> s;
  cin >> d;
  for (i=0;i<n;i++)
  {
   if (s[i]!=d[i])
   {
    if (!t) l=i,t=1;
    k=i;
   }
  }

   bool r=0,e=0;
   for (i=l+1;i<=k;i++)
   {
    if (s[i]!=d[i-1]) e=1;
    if (d[i]!=s[i-1]) r=1;
   }
   if (e && r) cout << 0; else
   if (!e && !r) cout << 2; else cout << 1;

  return 0;
}