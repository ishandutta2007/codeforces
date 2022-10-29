#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,p1,k1;
long long ans,sum;
int size[100001],fox[100001],fa[100001];
struct Node{int ed,before;}s[200001];
void dfs(int x)
{ int i; long long Rp=0;
   size[x]=1;
   for (i=fox[x];i;i=s[i].before)
    if (s[i].ed!=fa[x]) 
    {  fa[s[i].ed]=x; 
	   dfs(s[i].ed);
	    Rp+=1ll*size[x]*size[s[i].ed];
        size[x]+=size[s[i].ed];
   }
   ans-=(long long)1ll*Rp*1ll*(Rp+2ll*size[x]*(n-size[x]));
}
/*void Dfs(int x)
{  long long Rp=0; int i;
   sum+=1ll*size[x]*(n-size[x])*(n-size[x]);
   for (i=fox[x];i;i=s[i].before)
      if (s[i].ed!=fa[x])
     sum+=size[s[i].ed]*(size[x]-size[s[i].ed]-1)*(n-size[x])*(n-size[x]);
    for (i=fox[x];i;i=s[i].before)
     if (s[i].ed!=fa[x])
      Dfs(s[i].ed);
}*/ 
void add(int p1,int p2) {s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1; }
int main()
{ scanf("%d",&n);
    ans=1ll*n*(n-1)/2;
    ans=ans*ans;
   for (i=1;i<n;i++) scanf("%d%d",&p,&p1),add(p,p1),add(p1,p);
   dfs(1);
   
   //Dfs(1);  
   printf("%I64d\n",ans);
}