#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
map<pair<int,int>,int>mp;
char c;
map<pair<int,int>,int>::iterator it;
int i,j,m,n,p,k,vis[100001],R[100001][31],size[100001];
bool check(int x)
{ int i;
  for (i=1;i<=R[x][0];i++)
 {    it=mp.lower_bound(make_pair(R[x][i],0));
      if ((it->first).first==R[x][i]) 
      { printf("Conflict with %d\n",(it->first).second); return false; }
 } 
 return true;
}
void insert(int x)
{ int i;
 for (i=1;i<=R[x][0];i++) mp[make_pair(R[x][i],x)]=1;
}
void del(int x)
{ int i;
 for (i=1;i<=R[x][0];i++) mp.erase(make_pair(R[x][i],x));
}
int main()
{ scanf("%d%d",&n,&m);
  mp[make_pair(10000000,10000000)]=1;
  for (i=1;i<=n;i++) 
  {  for (j=2,k=i;j*j<=k;j++)
    if (k%j==0) 
   {   R[i][++R[i][0]]=j;
       while (k%j==0) k/=j;
   }
    if (k>1) R[i][++R[i][0]]=k;
  }
  for (i=1;i<=m;i++)
 {  while (c=getchar(),c!='+'&&c!='-');
    if (c=='+')
  { scanf("%d",&k);
    if (vis[k]) printf("Already on\n");
    else if (check(k)) printf("Success\n"),insert(k),vis[k]=1;
  }
  else {  scanf("%d",&k);
          if (!vis[k]) printf("Already off\n");
          else vis[k]=0,printf("Success\n"),del(k);
       }
 }
 }