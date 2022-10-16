#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
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
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
const int xx=1e6+5,mod=998244353;
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
int n,m,k,q,p[xx],to[xx];
char s[xx];
vector<int>v[xx];
int stk[xx],top;
int l[xx],r[xx];
int L[xx],R[xx];//range
void dfs(int x)
{
	if(l[x])dfs(l[x]),L[x]=L[l[x]];
	if(r[x])dfs(r[x]),R[x]=R[r[x]];
}
int I[xx];
//x 
void sufM(int l,int r){for(int i=r-1;i>=l;i--)I[i]=max(I[i],I[i+1]);}
void preM(int l,int r){for(int i=l+1;i<=r;i++)I[i]=max(I[i],I[i-1]);}
// V 
struct pr{int x,y;};
vector<pr>toL[xx];
vector<pr>toR[xx];
void run(int x)
{
	if(l[x])run(l[x]);
	if(r[x])run(r[x]);
	int Ll=L[x],Lr=x,Rl=x,Rr=R[x];
	// 
	int lenL=Lr-Ll+1,lenR=Rr-Rl+1;
	if(Lr-Ll+1<=Rr-Rl+1)
	{
		for(int i=Ll;i<=Lr;i++)I[i]=0;
		//max 
		for(auto it:v[p[x]])
		{
			int Tl=to[it],Tr=to[p[x]/it];
			if(Tl>Tr)swap(Tl,Tr);
			if(Tl==Tr)continue;
//			if(x==3)cout<<x<<' '<<p[x]<<" "<<it<<" "<<Tl<<" "<<Tr<<"qqq  ASD\n";
			if(Ll<=Tl&&Tl<=Rr&&Ll<=Tr&&Tr<=Rr)
			{
				if(Tl>=x)
					I[x]=max(I[x],min(lenR,Rr-Tr+1));
				else I[Tl]=max(I[Tl],min(lenR,Rr-Tr+1));
			}
			
		}
		// 
		sufM(Ll,Lr);
		for(int i=Ll;i<=Lr;i++)
			toL[i].push_back({Rr-I[i]+1,Rr});
	}
	else 
	{
		for(int i=Rl;i<=Rr;i++)I[i]=0; 
		for(auto it:v[p[x]])
		{
			int Tl=to[it],Tr=to[p[x]/it];
			if(Tl>Tr)swap(Tl,Tr);
//			if(Tl==Tr)
//			{
//				cout<<Tl<<" "<<Tr<<"#@#$$\n";
//			}
			if(Tl==Tr)continue;
			if(Ll<=Tl&&Tl<=Rr&&Ll<=Tr&&Tr<=Rr)
			{
				if(Tr<=x)
					I[x]=max(I[x],min(lenL,Tl-Ll+1));
				else I[Tr]=max(I[Tr],min(lenL,Tl-Ll+1));
			}
		}
		preM(Rl,Rr);
		for(int i=Rl;i<=Rr;i++)
			toR[i].push_back({Ll,Ll+I[i]-1});
	}
}
//int sum[xx];
//int lb(int x){return x&-x;}
//void add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
//ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
ll sum[xx<<2],adt[xx<<2];
void ad(int k,int l,int r,ll z){sum[k]+=(r-l+1)*z;adt[k]+=z;}
void pd(int k,int l,int r)
{
	int mid=l+r>>1;
	if(adt[k])
	{
		ad(k<<1,l,mid,adt[k]);
		ad(k<<1|1,mid+1,r,adt[k]);
		adt[k]=0;
	}
}
void cg(int k,int l,int r,int x,int y,ll z)
{
	if(x>y)return;
	if(x<=l&&r<=y)return ad(k,l,r,z);
	pd(k,l,r);int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
ll ask(int k,int l,int r,int x,int y)
{
	if(x>y)return 0;
	if(x<=l&&r<=y)return sum[k];
	pd(k,l,r);int mid=l+r>>1;
	ll ans=0;
	if(x<=mid)ans+=ask(k<<1,l,mid,x,y);
	if(mid<y)ans+=ask(k<<1|1,mid+1,r,x,y);
	return ans;
}
ll ans[xx];
struct nod{int l,r,id;}Q[xx];
void rg(int l,int r,int z){cg(1,1,n,l,r,1);/*add(l,z),add(r+1,-z);*/}
ll get(int l,int r){return ask(1,1,n,l,r);}
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=n;i++)to[p[i]]=i;
	//2 
	// 
	for(int i=1;i<=2e5;i++)
		for(int j=i;j<=2e5;j+=i)v[j].push_back(i);
	for(int i=1;i<=n;i++)L[i]=R[i]=i;
	//0stk0 
	for(int i=1;i<=n;i++)
	{
		int ls=0;
		while(top&&p[i]>p[stk[top]])ls=stk[top],top--;
		l[i]=ls,r[stk[top]]=i,stk[++top]=i;
	}
	dfs(r[0]),run(r[0]);
//	puts("");
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<"!!\n";
//		for(auto it:toL[i])
//			cout<<it.x<<" "<<it.y<<"!\n";
//	}
//	puts("RRRR");
//	
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<"!!\n";
//		for(auto it:toR[i])
//			cout<<it.x<<" "<<it.y<<"!\n";
//	}
//	puts("");
	//11 
	for(int i=1;i<=q;i++)
	{
		Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
//		if(Q[i].l<=to[1]&&to[1]<=Q[i].r)ans[i]--,cerr<<i<<"%^&^%&%^&\n";
	}
	sort(Q+1,Q+q+1,[&](nod&a,nod&b){return a.r<b.r;});
	int tt=1;
	for(int i=1;i<=q;i++)
	{
		while(tt<=Q[i].r)
		{
			for(auto it:toR[tt])rg(it.x,it.y,1);
			tt++;
		}
		ans[Q[i].id]+=get(Q[i].l,Q[i].r);
	}
	memset(sum,0,sizeof(sum));
	memset(adt,0,sizeof(adt));
	sort(Q+1,Q+q+1,[&](nod&a,nod&b){return a.l>b.l;});
	tt=n;
//	cout<<get(1,n)<<"$%^\n";
	for(int i=1;i<=q;i++)
	{
		while(tt>=Q[i].l)
		{
			for(auto it:toL[tt])rg(it.x,it.y,1);
			tt--;
		}
		ans[Q[i].id]+=get(Q[i].l,Q[i].r);
//		cout<<get(1,n)<<" "<<get(Q[i].l,Q[i].r)<<" qqq "<<tt<<"!!\n";
	}
//	cout<<ans[1]<<"$\n";
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}