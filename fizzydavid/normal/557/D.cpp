//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m,sz[200111];
struct DSU
{
	int f[200111],sz[200111];
	DSU(){for(int i=1;i<=200000;i++)f[i]=i,sz[i]=1;}
	int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
	bool un(int x,int y)
	{
		x=gf(x),y=gf(y);
		if(x==y)return true;
		f[x]=y;sz[y]+=sz[x];
		return false;
	}
}d1,d2;
bool c[200111];
int cnt[200111];
int main()
{
	scanf("%d%d",&n,&m);
	if(m==0)
	{
		printf("3 %I64d\n",1ll*n*(n-1)*(n-2)/6);
		return 0;
	}
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		d1.un(x,y+n);
		d1.un(x+n,y);
		d2.un(x,y);
	}
	for(int i=1;i<=n;i++)if(d1.gf(i)==d1.gf(i+n))
	{
		printf("0 1\n");
		return 0;
	}
	bool ok=0;
	int tcnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!c[d2.gf(i)]&&d2.sz[i]==2)c[d2.gf(i)]=1,tcnt++;
		if(d2.sz[d2.gf(i)]>2)
		{
			ok=1;
			break;
		}
	}
	if(!ok)
	{
		printf("2 %I64d\n",1ll*tcnt*(n-2));
		return 0;
	}
	for(int i=1;i<=n;i++)cnt[d1.gf(i)]++;
	ll ans=0;
	for(int i=1;i<=2*n;i++)if(cnt[i]>1)ans+=1ll*cnt[i]*(cnt[i]-1)/2;
	printf("1 %I64d\n",ans);
	return 0;
}