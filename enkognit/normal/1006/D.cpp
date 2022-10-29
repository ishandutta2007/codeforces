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

ll n,m,k,l,r=0,i,j,w,x,y;ll a[200001];

string s,d;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  cin >> s;
  cin >> d;
  s=' '+s;d=' '+d;
  for (i=1;i<=n/2;i++)
  {
   map<char,ll> t={};
   t[s[i]]++;
   t[s[n-i+1]]++;
   t[d[i]]++;
   t[d[n-i+1]]++;
   l=max(max(t[s[i]],t[s[n-i+1]]),max(t[d[i]],t[d[n-i+1]]));
   r=min(min(t[s[i]],t[s[n-i+1]]),min(t[d[i]],t[d[n-i+1]]));
   //cout << s[i] << s[n-i+1] << d[i] << d[n-i+1] <<" "<< l << " " << r << "\n";
   if (l==1 && r==1) k+=2; else
   if (l==2 && r==1)
   {k++;if (d[i]!=d[n-i+1] && s[i]==s[n-i+1])k++;}
   else
   if (l==3 && r==1) k++;
  }
  if (n%2==1)
  {
   if (s[n/2+1]!=d[n/2+1]) k++;
  }
  cout << k;
  return 0;
}