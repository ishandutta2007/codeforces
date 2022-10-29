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
string s;map<char,ll> t;

int main()
{
  //freopen("drying.in","r",stdin);
  //freopen("drying.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  cin >> s;
  for (i=0;i<n-1;i++)
  {
   for (char c='a';c<='z';c++) t[c]=0;
   for (j=i;j<n;j++)
   {
    t[s[j]]++;
    bool u=0;
    for (char c='a';c<='z';c++)
     if (t[c]>(j-i+1)/2) u=1;
    if (!u) {cout << "YES\n";cout << s.substr(i,j-i+1);exit(0);}
   }
  }
  cout << "NO\n";
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