#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
const int N=10000005;
typedef long long ll;
int pos[N];
inline ll min(const ll &a,const ll &b){return a<b?a:b;}
inline void chmin(ll &a,const ll &b){(a>b)&&(a=b);}
int main()
{
	int n,x,p1=0,p2=0;
	ll ans=0x7fffffffffffffff;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(pos[x]) 
		{
			if(ans>x)
			{
				ans=x;
				p1=pos[x],p2=i;
			}
		}
		else
		{
			pos[x]=i;
		}
	}
	for(register int i=1;i<=1e7;++i)
	{
		register int tmp=0,p=0;
		if(i>=ans) break;
		for(register int j=i;j<=1e7;j+=i)
		{
			if(pos[j])
			{
				if(tmp)
				{
					if(ans>1ll*j*tmp/i)
					{
						ans=1ll*j*tmp/i;
						p1=pos[j],p2=p;
					}
				}
				else
				{
					tmp=j;
					p=pos[j];
				}
			}
		}
	}
	if(p1<p2) printf("%d %d\n",p1,p2);
	else printf("%d %d\n",p2,p1);
	return 0;
}