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

ll n,m,k,l,r,i,j,w,x,y,p,a[200001];bool b[3];
string s;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> s;
  a[0]=0;
  for (i=0;i<s.size();i++) a[i+1]=((s[i]-48)%3+a[i])%3;
  b[0]=1;
  for (i=1;i<=s.size();i++)
   if (b[a[i]]==0 && (3+a[i]-l)%3!=0) b[a[i]]=1;else
   {
    k++;
    l=a[i];
    for (j=0;j<=2;j++) b[j]=0;
    b[a[i]]=1;
   }
  cout << k;
  return 0;
}