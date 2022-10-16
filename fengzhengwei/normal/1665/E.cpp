#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
// 
const int xx=5e5+5,mod=998244353;
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
int n,m,k,q,a[xx];
struct nod{int to[2],sum;}e[xx*40];//183MB
int cst,ncst;
void ins(int &k,int d,int x,int op)
{
	++cst,e[cst]=e[k],k=cst,e[k].sum+=op;
	if(d==-1)return;
	ins(e[k].to[x>>d&1],d-1,x,op);
}
int get(int a,int b,int d,int id)//dia 
{
	if(d==-1)return id;
	if(e[e[b].to[0]].sum-e[e[a].to[0]].sum)return get(e[a].to[0],e[b].to[0],d-1,id);
	if(e[e[b].to[1]].sum-e[e[a].to[1]].sum)return get(e[a].to[1],e[b].to[1],d-1,id+(1<<d));
//	cerr<<e[b].sum-e[a].sum<<" "<<d<<" "<<e[a].to[0]<<" "<<e[b].to[0]<<" "<<e[a].to[1]<<" "<<e[b].to[1]<<"!!\n";
	assert(0);
	return 0;
}
//trie
//or 
//+log^2 
//void down(int b,int d,int )
int ask(int a,int b,int d,int id)
{
	if(d==-1)return id;// 
	if(e[e[b].to[0]].sum-e[e[a].to[0]].sum>=2)return ask(e[a].to[0],e[b].to[0],d-1,id);
	// 
	if(e[e[b].to[0]].sum-e[e[a].to[0]].sum==0)return ask(e[a].to[1],e[b].to[1],d-1,id+(1<<d));
	if(e[e[b].to[0]].sum-e[e[a].to[0]].sum==1&&e[e[b].to[1]].sum-e[e[a].to[1]].sum==1)return get(e[a].to[0],e[b].to[0],d-1,id)|get(e[a].to[1],e[b].to[1],d-1,id+(1<<d));
	//loglog 
	if(e[e[b].to[0]].sum-e[e[a].to[0]].sum==1)
	{
		int N=get(e[a].to[0],e[b].to[0],d-1,id);
		int tb=b;
//		cerr<<N<<"!ASD\n";
		ins(b,d,N+(1<<d),1);
		return ask(e[a].to[1],e[b].to[1],d-1,id+(1<<d));
	}
	assert(0);
	return 0;
}
int rt[xx];
int A(int l,int r)
{
	int mn=2147483647;
	for(int i=l;i<=r;i++)
		for(int j=i+1;j<=r;j++)
			mn=min(mn,a[i]|a[j]);
	for(int i=l;i<=r;i++)
		for(int j=i+1;j<=r;j++)
	if(mn==(a[i]|a[j]))cerr<<i<<" "<<j<<"!!\n";
	return mn;
}
int main(){
//	freopen("a.out","w",stdout);
//	cout<<sizeof(e)/1024/1024<<"\n";
	int T=read();
	while(T--)
	{
		cst=ncst=0;
		mt19937 g(2);
		n=read();
//		n=100000;
		ll ans=0;
		for(int i=1;i<=n;i++)a[i]=/*g()%1073741824*/read(),rt[i]=rt[i-1],ins(rt[i],30,a[i],1);
		ncst=cst;
		int q=read();
//		int q=100000;
		while(q--)
		{
//			cerr<<q<<"!ASD\n";
			cst=ncst;// 
			int l=read(),r=read();
//			cout<<A(l,r)<<"!!\n";
			cout<<ask(rt[l-1],rt[r],30,0)<<"\n";
		}
	}
	pc('1',1);
	return 0;
}