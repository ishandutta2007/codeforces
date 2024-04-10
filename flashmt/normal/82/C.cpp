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

int n,par[5555],capa[5555],pos[5555],re[5555],used[5555];
vector<int> a[5555],c[5555];
vector < pii > b;

void visit(int x,int y,int cp)
{
   int i;
   par[x]=y; capa[x]=cp;
   fr(i,0,int(a[x].size())-1)
     if (a[x][i]!=y) visit(a[x][i],x,c[x][i]);
}

int main()
{
   int i,x,y,cp,time=0;
   cin >> n;
   fr(i,1,n) 
   {
      scanf("%d",&x); 
      if (i>1) b.pb(mp(x,i));
   }
   sort(b.begin(),b.end());
   fr(i,1,n-1)
   {
      scanf("%d%d%d",&x,&y,&cp);
      a[x].pb(y);
      a[y].pb(x);
      c[x].pb(cp);
      c[y].pb(cp);
   }
   visit(1,0,0);
   fr(i,0,n-2)  b[i].first=b[i].second;
   while (!b.empty())
   {
      memset(used,0,sizeof(used));
      ++time;
      //cout << "TIME = " << time << endl;
      fr(i,0,b.size()-1)
      {
         x=b[i].second;
         //cout << b[i].first << ": " << x << "->" << par[x] << endl; cin.get();
         if (used[x]<capa[x])
         {
            used[x]++;
            b[i].second=par[x];
         }
      }
      i=0;
      while (!b.empty() && i<b.size())
      {
         if (b[i].second==1)
         {
            re[b[i].first]=time;
            b.erase(b.begin()+i);
         }
         else i++;
      }
   }
   fr(i,1,n) printf("%d ",re[i]);
   printf("\n");
   return 0;
}