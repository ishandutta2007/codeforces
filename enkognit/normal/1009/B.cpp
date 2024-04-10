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

ll n,m,k,kn,kw,ke,ks,l,r,i,j,w,x,y,p,b[200001],c[200001];
bool t;
string s,d;

//struct thll{ll fi,se,th;};

ll a[200001];



int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> s;
  for (i=0;i<s.size();i++)
   if (s[i]=='1') k++;
   bool t=0;
  for (i=0;i<s.size();i++)
  {
   if (s[i]!='1')
   {
    if (s[i]=='2' && !t) {for (j=1;j<=k;j++) cout << '1';t=1;}
    cout << s[i];
   }
  }
  if (!t) for (i=1;i<=k;i++) cout << '1';
  return 0;
}