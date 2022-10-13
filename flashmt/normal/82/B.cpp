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

int n,s,c[444];
vector<int> a[444],v,re[44444];

int find(int x)
{
   int i;
   fr(i,0,int(v.size())-1)
     if (v[i]==x) return i;
   return -1;
}

int cmp(int x,int y)
{
   int i;
   fr(i,0,n-2)
    if (a[x][i]<a[y][i]) return -1;
    else if (a[x][i]>a[y][i]) return 1;
   return 0;
}

int main()
{
   int i,j,b,y,x;
   cin >> n;
   if (n==2)
   {
      cin >> b;
      fr(i,1,b) cin >> x,v.pb(x);
      sort(v.begin(),v.end());
      re[1].pb(v[0]);
      fr(i,1,b-1)
         if (v[i]!=v[i-1]) break;
         else re[1].pb(v[i]);
      cout << re[1].size() << " ";
      fr(i,0,re[1].size()-1) cout << re[1][i] << " ";
      cout << endl;
      cout << b-re[1].size() << " ";
      while (i<b) cout << v[i++] << " ";
      cout << endl;
      return 0;
   }
   fr(i,1,n*(n-1)/2)
   {
      cin >> b;
      fr(j,1,b) 
      {
         scanf("%d",&x);
         y=find(x);
         if (y<0)
         {
            v.pb(x);
            y=v.size()-1;
         }
         a[y].pb(i);
      }
   }
   fr(i,0,v.size()-1) sort(a[i].begin(),a[i].end());
   fr(i,0,v.size()-1)
   {
      c[i]=int(a[i].size())/(n-1);
      unique(a[i].begin(),a[i].end());
   }
//   fr(i,0,v.size()-1) {fr(j,0,a[i].size()-1)  cout << a[i][j] << " ";cout << endl;}
   fr(i,0,v.size()-2)
    fr(j,i+1,v.size()-1)
      if (cmp(j,i)<0) 
      {
         fr(x,0,n-2) swap(a[i][x],a[j][x]);
         swap(v[i],v[j]);
         swap(c[i],c[j]);
      }
   s=1;
   fr(x,1,c[0]) re[1].pb(v[0]);
   fr(i,1,v.size()-1)
     if (!cmp(i,i-1)) 
     {
       fr(x,1,c[i]) re[s].pb(v[i]);
     }
     else 
     {
       ++s;
       fr(x,1,c[i]) re[s].pb(v[i]);
     }
   fr(i,1,s)
   {
     printf("%d ",re[i].size());
     fr(j,0,re[i].size()-1) printf("%d ",re[i][j]);
     printf("\n");
   }
   return 0;
}