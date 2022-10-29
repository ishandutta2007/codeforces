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

const ld pi=22/7;
const ll MN=9e18;

ll n,p=0,k,b,m,i,j,o,l=0,ans,x,y,q,a[1001];
vector <ll> v;
string s;



int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input1.txt","r",stdin);
  //freopen("output1.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
   for (j=0;j<n;j++) {cin >> x;if (i==j) a[i+1]=x,l+=a[i+1];}
  cin >> m;
  for (i=0;i<m;i++)
  {
   cin >> x;
   if (x==3)cout << l%2;   else
   {
    cin >> y;
    if (a[y]) l--,a[y]--; else l++,a[y]++;
   }
  }

  return 0;
}