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
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

ll n,p=0,k,m,i,j,o,l,ans,x,y,a[100001],b[10001];
string s;
map <ll,ll> t;
vector <ll> c[100001];

bool comp(ll i,ll j)
{
 return a[i]>a[j];
}

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> m;
  for (i=0;i<m;i++)
  {
   cin >> n >> x >> y >> l;
   if (abs(x-y)%l!=0)
   {
    ll o=1e9;
    if (((n-y)%l)==0)o=min(o,(n-x)/l+(bool)(((n-x)%l))+(n-y)/l);
    if (((y-1)%l)==0)o=min(o,(x-1)/l+(bool)(((x-1)%l))+(y-1)/l);
    if (o==1e9) cout << -1; else cout << o;
   }else cout << abs(x-y)/l;
   cout << "\n";
  }

  return 0;
}