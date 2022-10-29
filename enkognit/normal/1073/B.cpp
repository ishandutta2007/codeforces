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
#define pu push
#define ld long double
#define pld pair<ld,ld>

using namespace std;

ll n,m,i,j,x,y,k,l,r,o,p[1000001];
string s;map<ll,ll> t;

int main()
{
  //freopen("drying.in","r",stdin);
  //freopen("drying.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) {cin >> x;t[x]=i;}
  for (i=1;i<=n;i++)
  {
   cin >> x;
   cout << max(0ll,t[x]-k) << " ";
   k=max(k,t[x]);
  }
  return 0;
}
/*l=1;
  i=2;
  j=n;r=1;
  for (i=2;i<=n;i++)
  {
   j=n;
   if (j%i==0) l++;
   while (j%i==0) j/=i;
  }
  cout << l;*/