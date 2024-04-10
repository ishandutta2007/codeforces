#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,tot;
int Tree[200001],vis[200001];
int Ans[200001];
int x[200001],a[200001],b[200001],c[200001];
void Do(int x)
{ int i,j,k=0,last,sum=0,X;
   for (i=1;i<=tot;i++) Tree[i]=0;
   for (i=x,last=x;i<=n;i+=p)
   {     k++;
        X=lower_bound(c+1,c+tot+1,a[i])-c;
        if (c[X]==a[i])
       {    Tree[X]++;
          if (Tree[X]==vis[X]) sum++;
       }
       if (k>m) {  X=lower_bound(c+1,c+tot+1,a[last])-c;
                   if (c[X]==a[last])
                    {  Tree[X]--;
                       if (Tree[X]==vis[X]-1) sum--;
                }
            last+=p;
        }
    if (sum==tot) Ans[++Ans[0]]=last;
}
}
int main()
{ scanf("%d%d%d",&n,&m,&p);
  if (n/p<m) printf("0\n");
else {
        for (i=1;i<=n;i++) scanf("%d",&a[i]);
		for (i=1;i<=m;i++) scanf("%d",&b[i]),c[i]=b[i];
		sort(c+1,c+m+1);
		tot=unique(c+1,c+m+1)-(c+1); 
		for (i=1;i<=m;i++)
		vis[lower_bound(c+1,c+tot+1,b[i])-c]++;
		for (i=1;i<=p;i++)
		 Do(i);
	printf("%d\n",Ans[0]);
	sort(Ans+1,Ans+Ans[0]+1);
	for (i=1;i<=Ans[0];i++) printf("%d ",Ans[i]);
}
}