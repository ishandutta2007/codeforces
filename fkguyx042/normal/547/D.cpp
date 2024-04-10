#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
using namespace std;
const int Maxp=200005;
map<pair<int,int>,int>mp;
int n,i,x[200005],y[200005];
set<int>v[500005];
void dfs(int x)
{
      int i;
      if (v[x].size())
      {
           int y=*v[x].begin();
           mp[make_pair(x,y)]=1;
           v[x].erase(y); v[y].erase(x);
           dfs(y);
      }
}          
int main()
{
     scanf("%d",&n);
     for (i=1;i<=n;++i)
     {
          scanf("%d%d",&x[i],&y[i]);
          y[i]+=Maxp;
          v[x[i]].insert(y[i]);
          v[y[i]].insert(x[i]);
     }
     for (i=1;i<=2*Maxp+1;++i) if (v[i].size()&1) dfs(i);
     for (i=1;i<=2*Maxp+1;++i) while(v[i].size())  dfs(i);
     for (i=1;i<=n;++i) 
      if (mp[make_pair(x[i],y[i])]) printf("r");
      else printf("b");
}