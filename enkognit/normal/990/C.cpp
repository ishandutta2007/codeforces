#include <bits/stdc++.h>

#define fr front
#define fi first
#define se second
#define pb push_back
#define ll long long
#define pu push
#define mp make_pair
#define pll pair<ll,ll>
#define len length()

using namespace std;

ll n,m,k,l,i,j,a[1000001],b[1000001];
string s[300001];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n;
  for (i=1;i<=n;i++)
  {
   cin >> s[i];
   if (s[i][0]=='(')
   {
    ll k=0;bool t=0;
    for (j=0;j<s[i].len;j++)
    {
     if (s[i][j]=='(') k++; else k--;
     if (k<0) {t=1;break;}
    }
    if (!t)a[300000+k]++;
   }
   if (s[i][s[i].len-1]==')')
   {
    ll k=0;bool t=0;
    for (j=s[i].len-1;j>=0;j--)
    {
     if (s[i][j]=='(') k++; else k--;
     if (k>0) {t=1;break;}
    }
    if (!t)b[300000-k]++;
   }
  }
  for (i=0;i<=1000000;i++) l+=a[i]*b[i];
  cout << l;
  return 0;
}