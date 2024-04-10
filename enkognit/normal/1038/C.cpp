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

ll n,i,j,p,x,y,m,l=0,l1,r,k=0;string s;
vector <ll> a,b;

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++) {cin >>x;a.pb(x);}
  for (i=0;i<n;i++) {cin >>x;b.pb(x);}
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  while (a.size()>0 || b.size()>0)
  {
   if (a.size()==0||(b.size()>0 && a.size()>0 && b.back()>=a.back()))b.erase(b.end()-1); else
   if (a.size()>0){k+=a.back();a.erase(a.end()-1);}
   if ((b.size()==0&&a.size()>0)||(b.size()>0 && a.size()>0 && a.back()>=b.back()))a.erase(a.end()-1); else
   if (b.size()>0){l+=b.back();b.erase(b.end()-1);}
  }
  cout << k-l;
  return 0;
}