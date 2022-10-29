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

using namespace std;

const ll N=2000001;

ll n,m,l,i,j,x,y,xx,yy,k,r;
string s[2];

int main()

{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<2229;i++) if (i%2)s[0]+='4'; else s[0]+='5';
  cout <<s[0]<< '5' << "\n";
  for (i=0;i<2229;i++) if (!(i%2))s[1]+='4'; else s[1]+='5';
  cout <<s[1]<< '5' << "\n";
  //system("pause");
  return 0;
}