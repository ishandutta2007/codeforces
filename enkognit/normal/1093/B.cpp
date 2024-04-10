#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double
#define y1 Enkognit

using namespace std;

ll n,m,i,j,k,l,a[10001];
string s,d;

int main()
{
  //freopen("backforth.in","r",stdin);
  //freopen("backforth.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (j=0;j<n;j++)
  {
   cin >> s;
   ll u=-1;
   bool t=0;
   for (i=0;i<s.size()/2;i++)
    if (s[i]!=s[s.size()-i-1]) {t=1;break;} else
    if (s[i]!=s[i+1]) u=i;
   if (t) cout << s << "\n"; else
   {
    if (u==-1) cout << -1 << "\n"; else
    {
     swap(s[u],s[u+1]);
     cout << s << "\n";
    }
   }

  }
}