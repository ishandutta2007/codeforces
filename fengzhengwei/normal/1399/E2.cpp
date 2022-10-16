#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T,n;
ll s;
const int xx=1e5+5;
struct nod{int next,to;ll w,c;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int a,int b)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].w=a,e[cnt].c=b;
}
int sum[xx];
struct node
{
	ll c,x,v;
	bool operator<(const node&w)const{return w.c==c?(v-v/2)*sum[x]<(w.v-w.v/2)*sum[w.x]:c<w.c;}
	///20 
};
priority_queue<node>q;
ll ans;
void dfs(int x,int y,ll d)
{
	int w=0;
	sum[x]=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;w=1;
		dfs(e[i].to,x,d+e[i].w);
		q.push((node){e[i].c,e[i].to,e[i].w});
		sum[x]+=sum[e[i].to];
	}
	if(!w)ans+=d,sum[x]=1;
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(e,0,sizeof(e[0])*(cnt+1));
		cnt=0;
		ans=0;
		while(!q.empty())q.pop();
		n=read(),s=read();
		memset(h,0,sizeof(h[0])*(n+1));
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read(),c=read(),d=read();
			add(a,b,c,d),add(b,a,c,d);
		}
		dfs(1,0,0);
		ans-=s;
		ll res=0;
		vector<ll>v;
//		cout<<ans<<'\n';
		while(ans>0)
		{
			node a=q.top();
			q.pop();
			if(a.c==2)v.push_back((a.v-a.v/2)*sum[a.x]);
			ans-=(a.v-a.v/2)*sum[a.x];
			res+=a.c;
//			cout<<a.c<<" "<<(a.v-a.v/2)*sum[a.x]<<"\n";
			if(a.v/2)q.push((node){a.c,a.x,a.v/2});
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		while(v.size()&&ans+*--v.end()<=0)ans+=*--v.end(),res-=2,v.pop_back();
		ll rans=res;
		while(!q.empty())
		{
			node a=q.top();
			q.pop();
			if(a.c==2)continue;
			if(a.c==1&&v.size())
			{
				res++;
				if(a.v/2)q.push((node){a.c,a.x,a.v/2});
				ans-=(a.v-a.v/2)*sum[a.x];
				while(v.size()&&ans+*--v.end()<=0)ans+=*--v.end(),res-=2,v.pop_back();
				rans=min(rans,res);
//				cout<<(a.v-a.v/2)*sum[a.x]<<" "<<a.v<<" "<<v.size()<<" "<<ans<<"\n";
			}
//			{res--;break;}
		}
		cout<<rans<<"\n";
	}
    return 0;
}