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

ll n,m,k,l,r,i,j,w,x,y,p,a[200001];
string s,d;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> s;
  cin >> d;
  i=s.size()-1;j=d.size()-1;
  while (i>=0 && j>=0 && s[i]==d[j])i--,j--;
  cout << i+j+2;
  return 0;
}