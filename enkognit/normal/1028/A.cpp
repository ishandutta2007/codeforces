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

ll n,m,l,i,j,x,y,xx,yy,k,r,a[N];
string s[10001];bool t;

int main()

{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++) cin >> s[i];
  for (i=0;i<n;i++)
   for (j=0;j<m;j++)
    if (s[i][j]=='B') {if (!t) {t=1;x=i+1;y=j+1;}xx=i+1;yy=j+1;}
  cout << (xx+x)/2 << " " << (yy+y)/2 << "\n";
  //system("pause");
  return 0;
}