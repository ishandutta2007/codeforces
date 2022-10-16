#include<bits/stdc++.h>
#define ll long long
#define dd double
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
int n,m,k;
const int xx=5e5+5,mod=998244353,base=117;
char s[xx],t[xx];
ll pw[xx],ni[xx];
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
ll sums[xx],sumt[xx];
ll gs(int l,int r){return (sums[r]-sums[l-1]+mod)*ni[l]%mod;}
ll gt(int l,int r){return (sumt[r]-sumt[l-1]+mod)*ni[l]%mod;}
int len[xx];
struct node{int next,to;}e[xx];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
//min 
int sum[xx];
int lb(int x){return x&-x;}
void ad(int x,int y)
{
	x=n-x+1;
	for(;x<=n;x+=lb(x))sum[x]=min(sum[x],y);
}
int ask(int x)
{
	x=n-x+1;
	int ans=1e9;
	for(;x;x-=lb(x))ans=min(ans,sum[x]);
	return ans;
}
void admx(int x,int y){for(;x<=n;x+=lb(x))sum[x]=max(sum[x],y);}
int askmx(int x)
{
	int ans=-1e9;
	for(;x;x-=lb(x))ans=max(ans,sum[x]);
	return ans;
}
int Mnl[xx],Mxr[xx];//x 
int main(){
	n=read(),m=read();
	k=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	pw[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i-1]*base%mod;
	ni[0]=1;
	ni[1]=ksm(pw[1],mod-2);
	for(int i=2;i<xx;i++)ni[i]=ni[i-1]*ni[1]%mod;
	for(int i=1;i<=n;i++)sums[i]=(sums[i-1]+(s[i]-'a')*pw[i])%mod;
	for(int i=1;i<=m;i++)sumt[i]=(sumt[i-1]+(t[i]-'a')*pw[i])%mod;
	for(int i=1;i<=n-m+1;i++)// 
	{
		if(gs(i,i+m-1)==gt(1,m))
		{
			puts("Yes");
			if(i+k+k-1<=n)
			{
				cout<<i<<" "<<i+k<<"\n";
				return 0;
			}
			cout<<n-k-k+1<<" "<<n-k+1<<"\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int l=i,r=min(n,i+m-1),ans=i-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(gs(i,mid)==gt(1,mid-i+1))ans=mid,l=mid+1;
			else r=mid-1;
		}
		add(ans-i+1,i);
	}
	memset(sum,0x3f,sizeof(sum));
	for(int x=m-1;x>=1;x--)// 
	{
		for(int i=h[x];i;i=e[i].next)ad(e[i].to,e[i].to);
		if(x<=k)Mnl[x]=ask(k-x+1)-(k-x);
		else Mnl[x]=1e9;
	}
	memset(e,0,sizeof(e[0])*(cnt+1));
	memset(h,0,sizeof(h));
	cnt=0;
	for(int i=1;i<=n;i++)//lcs 
	{
		int l=max(1,i-m+1),r=i,ans=i+1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(gs(mid,i)==gt(m-(i-mid+1)+1,m))ans=mid,r=mid-1;
			else l=mid+1;
		}
		add(i-ans+1,i);
	}
	//max(szsz) 
	memset(sum,-1e9,sizeof(sum));
	for(int x=m-1;x>=1;x--)// 
	{
		for(int i=h[x];i;i=e[i].next)admx(e[i].to,e[i].to);
		if(x<=k)Mxr[x]=askmx(n-k+x)-x+1;
		else Mxr[x]=-1e9;
	}
	for(int i=1;i<m;i++)
	{
		if(Mnl[i]+k<=Mxr[m-i])
		{
			puts("Yes");
			cout<<Mnl[i]<<" "<<Mxr[m-i]<<"\n";
			return 0;
		}
	}
	puts("No");
	return 0;
}