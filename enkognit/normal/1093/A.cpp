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
  for (i=0;i<n;i++)
  {
   ll x;
   cin >> x;
   cout << x/7+(x%7>0) << "\n";
  }
}