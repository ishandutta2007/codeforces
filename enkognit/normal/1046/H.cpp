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

ll n,m,i,u,j,o,k,l,a[30],b[30],w[30];map<ll,ll> t;
string s;

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  b[1]=1;
  k=1;
  for (char c='b';c<='z';c++) b[c-96]=b[c-97]*2;
  for (i=0;i<n;i++)
  {
   cin >> s;
   for (j=0;j<30;j++) a[j]=1;
   ll l=0;
   for (j=0;j<s.size();j++)
   l+=a[s[j]-97]*b[s[j]-96],a[s[j]-97]=-a[s[j]-97];
   for (char c='a'-1;c<='z';c++)
   {
    o+=t[b[c-96]^l];
    //if (t[b[c-96]^l])cout << (b[c-96]^l) << " " << s << "\n";
   }
   t[l]++;
  }
  cout << o;
  return 0;
}