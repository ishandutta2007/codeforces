#include<cstdio>
#include<algorithm>

using namespace std;

int x1[500],y1[500],y2[500],x2[500],i,j,x,y,n,aux1,aux2,mul;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]),x1[i]=x1[i]*2+100,x2[i]=x2[i]*2+100,y1[i]=y1[i]*2+100,y2[i]=y2[i]*2+100;

	for(i=2;i<=n;++i)
	{
		x=y=0;mul=0;
	 	for(j=i;j>1;--j)
		{
			aux1=max(x1[j]-x2[j],x2[j]-x1[j]);
			aux2=max(y1[j]-y2[j],y2[j]-y1[j]);
			mul+=aux1*aux2*aux1;
			x+=aux1*aux2*aux1*((x1[j]+x2[j])/2);
			y+=aux1*aux2*aux1*((y1[j]+y2[j])/2);
			aux1=min(x1[j-1],x2[j-1])*mul;
			aux2=max(x1[j-1],x2[j-1])*mul;
			if(aux1>x||aux2<x)
				break;

			aux1=min(y1[j-1],y2[j-1])*mul;
			aux2=max(y1[j-1],y2[j-1])*mul;
			if(aux1>y||aux2<y)
				break;
	}
		if(j!=1)
			break;
	}
	printf("%d",i-1);
}