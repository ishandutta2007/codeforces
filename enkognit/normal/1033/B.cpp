#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define len length()
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>

using namespace std;

ll n,m,i,j,k,x,y;
map <ll,bool> t;

int main()
{
  //freopen("cubroot.in","r",stdin);
  //freopen("cubroot.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> x >> y;
   if (x-y==1)
   {
    bool t=0;
    for (int j=2;j<=sqrt(2*1e11);j+=2)
     {if ((x+y)%j==0 && (x+y)!=j) {t=1;break;}if (j==2) j--;}
    if (!t)cout << "YES\n"; else cout <<"NO\n";
   }else cout << "NO\n";
  }
}