#include<cstdio>
#include<algorithm>

using namespace std;

int n,i,poz,p[250];

double t,v[250],m[250],x[250],aux,mint,tempv1,tempv2;

bool fcomp(int a,int b)
{
	return x[a]<x[b];
}

int main()
{
	scanf("%d",&n);scanf("%lf",&t);
	for(i=1;i<=n;++i)
		scanf("%lf",&x[i]),scanf("%lf",&v[i]),scanf("%lf",&m[i]),p[i]=i;
    sort(p+1,p+n+1,fcomp);
	do
	{
		mint=250.0;
		for(i=1;i<n;++i)
			if(v[p[i]]>v[p[i+1]])
			{
				aux=-(x[p[i]]-x[p[i+1]])/(v[p[i]]-v[p[i+1]]);
				if(aux<mint)
					mint=aux,poz=i;
			}
		if(mint>=t)
			break;
		t-=mint;
		for(i=1;i<=n;++i)
			x[i]+=v[i]*mint;
		tempv1=(m[p[poz]]-m[p[poz+1]])*v[p[poz]]+2*m[p[poz+1]]*v[p[poz+1]];
		tempv1/=m[p[poz]]+m[p[poz+1]];
		tempv2=(m[p[poz+1]]-m[p[poz]])*v[p[poz+1]]+2*m[p[poz]]*v[p[poz]];
		tempv2/=m[p[poz]]+m[p[poz+1]];
		v[p[poz]]=tempv1;
		v[p[poz+1]]=tempv2;
	}while(1);
	for(i=1;i<=n;++i)
		x[i]+=v[i]*t,printf("%.9lf\n",x[i]);
}