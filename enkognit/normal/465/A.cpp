#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ll n,m,j,i,l,r,k=0,o,p,a[10001],b[10001];
string s,d;
map <ll,bool> t;

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n;
 cin >> s;
 d=s;
 i=0;
 for (i=0;i<n;i++)
  if (d[i]=='1') d[i]='0'; else {d[i]=1;break;}
 for (i=0;i<n;i++) l+=(s[i]!=d[i]);
 cout << l;
}