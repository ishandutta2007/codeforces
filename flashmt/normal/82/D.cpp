#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<utility>
#include<set>
#include<sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};
      
int n,a[1111],f[1111][1111],re=oo,tr[1111][1111],last;
vector < pii > r;

int main()
{
   int i,j;
   cin >> n;
   fr(i,1,n) scanf("%d",&a[i]);
   if (n==1) cout << a[1] << endl << 1 << endl;
   else
   {
      if (n==2) cout << max(a[1],a[2]) << endl << "1 2" << endl;
      else
      {
         memset(f,oo,sizeof(f));
         fr(i,1,n)
          fr(j,1,i) f[i][j]=oo;
         f[3][1]=max(a[2],a[3]);
         f[3][2]=max(a[1],a[3]);
         f[3][3]=max(a[1],a[2]);
         i=3;
         while (i+2<=n)
         {
            i+=2;
            fr(j,1,i-2)
            {
               if (f[i][j]>f[i-2][j]+max(a[i],a[i-1]))
               {
                  f[i][j]=f[i-2][j]+max(a[i],a[i-1]);
                  tr[i][j]=j;
               }
               if (f[i][i]>f[i-2][j]+max(a[j],a[i-1]))
               {
                  f[i][i]=f[i-2][j]+max(a[j],a[i-1]);
                  tr[i][i]=j;
               }
               if (f[i][i-1]>f[i-2][j]+max(a[j],a[i]))
               {
                  f[i][i-1]=f[i-2][j]+max(a[j],a[i]);
                  tr[i][i-1]=j;
               }
            }
         }
         if (i==n)
         {
            fr(j,1,n)
              if (f[n][j]!=oo && re>f[n][j]+a[j])
              {
                 re=f[n][j]+a[j]; last=j;
              }
            j=last;
            r.pb(mp(j,0));     
         }
         else
         {
            fr(j,1,n)
              if (f[n-1][j]!=oo && re>f[n-1][j]+max(a[n],a[j]))
              {
                 last=j; re=f[n-1][j]+max(a[n],a[j]);
              }
            j=last;
            r.pb(mp(j,n));              
         }
         while (i>3)
            {
               int k=tr[i][j];
               if (k==j) r.pb(mp(i-1,i));
               else
               {
                  if (j==i) r.pb(mp(k,i-1));
                  else r.pb(mp(k,i));
               }
               j=k;
               i-=2;
            }  
         if (j==1) r.pb(mp(2,3));
         if (j==2) r.pb(mp(1,3));
         if (j==3) r.pb(mp(1,2)); 
         cout << re << endl;
         frr(i,r.size()-1,1) printf("%d %d\n",r[i].first,r[i].second);
         cout << r[0].first << " ";
         if (n%2==0) cout << r[0].second;
         cout << endl;
      }
   }
   return 0;
}