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

using namespace std;

ll n,m,k,i,j,l,r;pll a[1000001];
string s[10001];
bool t[1001][1001];

int main()
{
  //freopen("cubroot.in","r",stdin);
  //freopen("cubroot.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++)cin >> s[i];
  for (i=0;i<n;i++)
   for (j=0;j<m;j++)
    if (s[i][j]=='#')
    {
     bool u=0;
     if (s[i+1][j]=='#' && s[i+2][j]=='#' && s[i][j+1]=='#' && s[i][j+2]=='#'
         && s[i+1][j+2]=='#' && s[i+2][j+1]=='#' && s[i+2][j+2]=='#')
     {
      t[i][j]=1;
      t[i+1][j]=1;
      t[i+2][j]=1;
      t[i][j+1]=1;
      t[i][j+2]=1;
      t[i+1][j+2]=1;
      t[i+2][j+1]=1;
      t[i+2][j+2]=1;
     }
     if (!t[i][j]) {cout << "NO";exit(0);}
    }
   cout << "YES";
}