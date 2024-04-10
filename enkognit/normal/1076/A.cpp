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

ll n,m,i,j,k,l=0,x,y,h,r,o,p=0,d[500001],a[500001];
string s;


int main()
{
  //freopen("div7.in","r",stdin);
  //freopen("div7.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  cin >> s;
  for (i=1;i<n;i++) if (s[i]<s[i-1]) {s.erase(i-1,1);cout << s;exit(0);}
  s.erase(s.size()-1,1);
  cout << s;
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