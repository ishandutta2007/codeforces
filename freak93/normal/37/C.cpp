#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int aux[1005],n,i,j,p[1005],a[1005],ans[1005][1005];

bool add(int poz)
{
	if(poz==0)
		return false;
    if(aux[poz]==1)
	{
		aux[poz]=0;
		return add(poz-1);
	}
	aux[poz]=1;
	return true;
}

bool fcomp(int x,int y)
{
	return a[x]<a[y];
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]),p[i]=i;
	sort(p+1,p+n+1,fcomp);
	for(i=1;i<=n;++i)
	{
		memcpy(ans[p[i]],aux,sizeof(aux));
		if(add(a[p[i]])==false&&i<n)
		{
			printf("NO");
			return 0;
		}
	}
	
	printf("YES\n");
	for(i=1;i<=n;++i,printf("\n"))
		for(j=1;j<=a[i];++j)
			printf("%d",ans[i][j]);
}