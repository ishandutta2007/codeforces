#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,u,v,i,j,k,a,now,ans,tmp;
int fa[100005],cnt[100005];
int num[100005],f[100005],val[100005],q[100005],ll,rr;

int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool luck(int x)
{
	if(!x)return true;
	return (x%10==4||x%10==7)&&luck(x/10);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)fa[i]=i;
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		u=get(u);v=get(v);
		fa[u]=v;
	}
	for(i=1;i<=n;++i)++cnt[get(i)];
	for(i=1;i<=n;++i)if(fa[i]==i)++num[cnt[i]];
	for(i=1;i<=n;++i)f[i]=1000000;
	for(i=1;i<=n;++i)
	if(num[i])
	{
		for(j=0;j<i;++j)
		{
			ll=1;rr=0;now=0;
			for(k=j;k<=n;k+=i)
			{
				++now;tmp=f[k]-now;
				if(ll<=rr&&now-q[ll]>num[i])++ll;
				while(ll<=rr&&tmp<=val[rr])--rr;
				q[++rr]=now;val[rr]=tmp;
				f[k]=val[ll]+now;
			}
		}
	}
	ans=1000000;
	for(i=1;i<=n;++i)if(luck(i)&&f[i]<ans)ans=f[i];
	if(ans>233333)printf("-1\n");
	else printf("%d\n",ans-1);
}