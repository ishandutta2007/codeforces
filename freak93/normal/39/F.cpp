#include<cstdio>

using namespace std;

int i,j,m,n,k,ans[500],d[500],v[500],rez,aux;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i)
		scanf("%d",&d[i]);
	for(i=1;i<=k;++i)
		scanf("%d",&v[i]);
	rez=k+1;
	for(i=1;i<=m;++i)
	{
		aux=0;
		for(j=1;j<=k;++j)
			if(v[j]%d[i]==0)
				++aux;
		if(aux<rez)
			rez=aux,ans[ans[0]=1]=i;
		else
			if(aux==rez)
				ans[++ans[0]]=i;
	}
	printf("%d\n",ans[0]);
	for(i=1;i<=ans[0];++i)
		printf("%d ",ans[i]);
}