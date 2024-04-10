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
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>

using namespace std;

ll n,i,j,k,p,x,y,u,m,l,r,a[300001];
string s,d,g;char c;
map <char,ll> t;

int main()
{
  //freopen("yogurt.in","r",stdin);
  //freopen("yogurt.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  cin >> s;
  for (i=0;i<n;i++) t[s[i]]++;
  for (char i='a';i<='z';i++)
   for (j=0;j<t[i];j++) cout << i;
 return 0;
}