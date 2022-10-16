#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=1e5+5,mod=1e9+7;
struct nod{int next,to,v,col;}e[xx<<1];
int cnt,h[xx],n;
void add(int x,int y,int a,int b){cnt++;e[cnt]={h[x],y,a,b};h[x]=cnt;}
ll ans=1;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
namespace cdq
{
	struct N{int id,a,b,pd,op;}e[xx<<1],w[xx<<1];
	//w 
	//int 
	int sum[xx<<2],sum2[xx<<2];
	int lb(int x){return x&-x;}
	void add(int x,int y){x+=n+n;for(;x<(xx<<2);x+=lb(x))sum[x]=1ll*sum[x]*y%mod,sum2[x]++;}
	int ask(int x){x+=n+n;int ans=1;x=min(x,(xx<<2)-1);for(;x;x-=lb(x))ans=1ll*ans*sum[x]%mod;return ans;}
	int ask2(int x){x+=n+n;int ans=0;x=min(x,(xx<<2)-1);for(;x;x-=lb(x))ans+=sum2[x];return ans;}
	void cls(int x){x+=n+n;for(;x<(xx<<2);x+=lb(x))sum[x]=1,sum2[x]=0;}
	//dltn+n()ask-n 
	int tt;
	int G0(N&w){return w.op?w.a+w.a-w.b:w.b-w.a-w.a;}
	int G1(N&w){return w.op?w.b+w.b-w.a:w.a-w.b-w.b;}
	void cdq(int l,int r)
	{
		if(l==r)return;
		int mid=l+r>>1;
		cdq(l,mid),cdq(mid+1,r);
		//0->b-2a 1->2a-b  
		//0->a-2b 1->2b-a 
		//bel 
		int mn=1e9;
		for(int i=mid+1;i<=r;i++)mn=min(mn,e[i].id);
		int gtt=l-1;
		//<mn -> >=mn =mn -> >mn 
		//<= 
//		cout<<l<<" "<<mid<<" "<<r<<" QQQ \n";
//		for(int i=l;i<=r;i++)
//		{
//			cout<<e[i].id<<" "<<e[i].a<<" "<<e[i].b<<" "<<e[i].pd<<" "<<e[i].op<<" "<<G0(e[i])<<" "<<G1(e[i])<<"!\n";
//		}
//		puts("");
		// 
		int lps=l,rps=mid+1;
		while(lps<=mid&&rps<=r)
		{
			if(G0(e[lps])<=G0(e[rps]))
			{
				w[++gtt]=e[lps];
				if(e[lps].id<mn&&e[lps].op==0)add(G1(e[lps]),e[lps].pd);
				lps++;
			}
			else 
			{
				w[++gtt]=e[rps];
				if(e[rps].id>=mn&&e[rps].op==1)ans*=1ll*ask(G1(e[rps]))*ksm(e[rps].pd,ask2(G1(e[rps])))%mod,ans%=mod;
				rps++;
			}
		}
		while(lps<=mid)
			{
				w[++gtt]=e[lps];
				if(e[lps].id<mn&&e[lps].op==0)add(G1(e[lps]),e[lps].pd);
				lps++;
			}
		while(rps<=r)
			{
				w[++gtt]=e[rps];
				if(e[rps].id>=mn&&e[rps].op==1)ans*=1ll*ask(G1(e[rps]))*ksm(e[rps].pd,ask2(G1(e[rps])))%mod,ans%=mod;
				rps++;
			}
		for(int i=l;i<=mid;i++)cls(G1(e[i]));
		lps=l,rps=mid+1;
		while(lps<=mid&&rps<=r)
		{
			if(G0(e[lps])<=G0(e[rps]))
			{
				if(e[lps].id==mn&&e[lps].op==0)add(G1(e[lps]),e[lps].pd);
				lps++;
			}
			else 
			{
				if(e[rps].id>mn&&e[rps].op==1)ans*=1ll*ask(G1(e[rps]))*ksm(e[rps].pd,ask2(G1(e[rps])))%mod,ans%=mod;
				rps++;
			}
		}
		while(lps<=mid)
			{
				if(e[lps].id==mn&&e[lps].op==0)add(G1(e[lps]),e[lps].pd);
				lps++;
			}
		while(rps<=r)
			{
				if(e[rps].id>mn&&e[rps].op==1)ans*=1ll*ask(G1(e[rps]))*ksm(e[rps].pd,ask2(G1(e[rps])))%mod,ans%=mod;
				rps++;
			}
		for(int i=l;i<=mid;i++)cls(G1(e[i]));
		for(int i=l;i<=r;i++)e[i]=w[i];
//		cout<<ask2(200000)<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	}
	//id 
	void solve(){/*cout<<1<<" "<<tt<<" ";puts("ST one ");*/cdq(1,tt);}
	void init(){for(int i=0;i<(xx<<2);i++)sum[i]=1;}
}
int vis[xx],size[xx],mx[xx],TT,cur;
void findc(int x,int y)
{
	size[x]=1,mx[x]=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(vis[e[i].to]||e[i].to==y)continue;
		findc(e[i].to,x),size[x]+=size[e[i].to],mx[x]=max(mx[x],size[e[i].to]);
	}
	mx[x]=max(mx[x],TT-size[x]);
	if(!cur||mx[x]<mx[cur])cur=x;
}
// 
void in(int x,int y,int bel,int a,int b,int pd)
{
	cdq::e[++cdq::tt]={bel,a,b,pd,0};
	cdq::e[++cdq::tt]={bel,a,b,pd,1};
	if(min(a,b)*2>=max(a,b))ans*=pd,ans%=mod;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[e[i].to])continue;
		in(e[i].to,x,bel,a+(e[i].col==0),b+(e[i].col==1),1ll*pd*e[i].v%mod);
	}
}
void dfz(int x)
{
	if(TT==1)return;
	cur=0,findc(x,0);
	x=cur,vis[x]=1;
//	cout<<x<<" "<<TT<<"!!\n";
	int Id=0;
	cdq::tt=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(vis[e[i].to])continue;
		in(e[i].to,x,++Id,(e[i].col==0),(e[i].col==1),e[i].v);
	}
	cdq::solve();
	///fn 
//	cout<<ans<<"!!\n";
//	exit(0);
	// 
	for(int i=h[x],sum=TT;i;i=e[i].next)
	{
		if(vis[e[i].to])continue;
		if(size[e[i].to]>size[x])TT=sum-size[x];
		else TT=size[e[i].to];
		dfz(e[i].to);
	}
}
int main(){
	cdq::init();
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read(),c=read(),d=read();
		add(a,b,c,d),add(b,a,c,d);
	}
	TT=n;
	dfz(1);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}