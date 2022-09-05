//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,head[200111],nxt[400111],to[400111],lim[400111],w[400111],tot=1;
ll sumw[400111],v[400111],tv[400111];
ll dfs(int x,int pre=-1)
{
	ll sum=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==pre)continue;
		ll t=dfs(to[i],x);
		v[i]=lim[i]-sumw[to[i]];
		tv[i]=max(0ll,-v[i]-t);
		sum+=t+tv[i];
//		cout<<x<<" "<<to[i]<<" "<<v[i]<<","<<tv[i]<<endl;
		sumw[x]+=sumw[to[i]]+w[i];
	}
	return sum;
}
ll temp=0;
pair<ll,ll> solve(int x,ll a=0,int pre=-1)
{
//	cout<<"solve:"<<x<<" "<<a<<endl;
	ll ret0=0,ret=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==pre)continue;
		pair<ll,ll> tmp=solve(to[i],a-ret+tv[i],x);
		tmp.SS-=tv[i];
		v[i]+=tmp.FF;
		ret0+=tmp.FF;
		ret+=tmp.SS;
		if(v[i]>=0)
		{
			ll dlt=max(0ll,min(a-ret,min(v[i],w[i]-1ll)));
			ret0+=dlt;
			ret+=dlt;
			v[i]-=dlt;
			lim[i]-=dlt;lim[i^1]-=dlt;
			w[i]-=dlt;w[i^1]-=dlt;
			temp+=dlt;
		}
		else
		{
			puts("-1");
			exit(0);
		}
	}
//	cout<<x<<" return "<<ret0<<","<<ret<<endl;
	return MP(ret0,ret);
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y,ll,ww;
		scanf("%d%d%d%d",&x,&y,&ww,&ll);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		lim[tot]=ll;
		w[tot]=ww;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
		lim[tot]=ll;
		w[tot]=ww;
	}
	dfs(1);
	solve(1);
	printf("%d\n",n);
	for(int i=2;i<2*n;i+=2)printf("%d %d %d %d\n",to[i^1],to[i],w[i],lim[i]);
//	cout<<"tmp="<<temp<<endl;
	return 0;
}