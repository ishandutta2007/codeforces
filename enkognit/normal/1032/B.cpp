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
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

ll n,m,i,j,forw,k,l=0,r,o,p=0;ll a[100001],b[100001];
string s;
vector <ll> v;
map<ll,ll> t;

int main()
{
  //freopen("digits.in","r",stdin);
  //freopen("digits.out","w",stdout);
  fast_io;
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> s;
  for (i=1;i<=5;i++)
  {
   ll n=s.size()/i+(s.size()%i>0),m=s.size()%i;
   if (n>20) continue;
   bool u=(m>0);
   cout << i << " " << n << "\n";
   while (s.size()>0)
   {
    if (m==0 && u) {for (j=0;j<n-1;j++) {cout << s[j];}cout << "*\n";s.erase(0,n-1);}
    if (m>0) {for (j=0;j<n;j++) {cout << s[j];}cout << "\n";m--;s.erase(0,n);}
    if (m==0 && !u){for (j=0;j<n;j++) {cout << s[j];}cout << "\n";s.erase(0,n);}
   } exit(0);
  }
  return 0;
}