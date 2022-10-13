#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#define fr(a,b,c) for(a=b;a<=c;a++)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;

int m,n,re[1111];
vector < pii > a;

int main()
{
   int i,j,x,y;
   cin >> n >> m;
   fr(i,1,m) cin >> x,a.pb(mp(x,i));
   sort(a.begin(),a.end());
   i=0; y=n; x=m-1;
   while (y)
   {
     while ((!a[x].first || re[(i+1)%n]==a[x].second || re[(i+n-1)%n]==a[x].second) && x>=0) x--;
     if (x<0) break;
     re[i]=a[x].second; a[x].first--;
     i+=2; y--;
     if (i>=n) i=1;
   }
   if (y) cout << -1;
   else fr(i,0,n-1) cout << re[i] << " ";
   cout << endl;
   return 0;     
}