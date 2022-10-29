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
#define y1 Enkognit

using namespace std;

ll p,n,k,m,i,j,o,l,r,ans,x,y,a[1000001],q,x4,y4,x1,y1,x2,y2,x3,y3;
//vector<ll> b[1000001];

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> q;
  for (i=0;i<q;i++)
  {
   cin >> n >> m;
   o=n*m/2;
   p=n*m/2;
   if (n*m%2) o++;
   cin >> x1 >> y1 >> x2 >> y2;
   cin >> x3 >> y3 >> x4 >> y4;
   ll d1=x2-x1+1,d2=y2-y1+1,d3=x4-x3+1,d4=y4-y3+1;
   p-=d1*d2/2+(d1*d2%2)*((x1+y1)%2),o+=d1*d2/2+(d1*d2%2)*((x1+y1)%2);
   o-=d3*d4/2+(d3*d4%2)*((x3+y3)%2==0),p+=d3*d4/2+(d3*d4%2)*((x3+y3)%2==0);
   ll nx1=max(x1,x3),ny1=max(y1,y3),nx2=min(x2,x4),ny2=min(y2,y4);
   if (!(nx1>nx2 || ny1>ny2))
   {
    ll r=(nx2-nx1+1)*(ny2-ny1+1)/2+((nx1+ny1)%2)*((nx2-nx1+1)*(ny2-ny1+1)%2);
    p+=r,o-=r;
   }
   cout << o << " " << p << "\n";
  }
  return 0;
}