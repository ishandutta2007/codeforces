#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>

using namespace std;

int n,m,j,l,r,k,ans,len,q;
vector<ll> v,d[2];
string s;

int main()
{
  //freopen("pizza.in","r",stdin);
  //freopen("pizza.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> s;
  if (s.size()==1) k=atoi(s.substr(s.size()-1,1).c_str()); else
  k=atoi(s.substr(s.size()-2,2).c_str());
  ans=1;
  if (k%2) ans+=4; else ans+=1;
  if (k%4==0) ans+=2; else
  if (k%4==1 || k%4==3) ans+=5; else
  if (k%4==2) ans+=8;
  cout << ans%5;
}