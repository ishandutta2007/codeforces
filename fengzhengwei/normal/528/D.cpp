#include<bits/stdc++.h>
#define ll long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
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
	wt(x),pc(op,0);
}
const int xx=1e6+5,mod=998244353;
int n,m,k;
char s[xx],c[xx];
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*a*ans%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int W[xx],w[xx],rev[xx],N;
int make(int n)
{
	int t=ceil(log2(n));N=(1<<t);
	for(int i=1;i<N;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(t-1));
	W[0]=1,W[1]=ksm(3,(mod-1)/N);
	for(int i=2;i<N;i++)W[i]=1ll*W[i-1]*W[1]%mod;
	return N;
}
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int red(int a){return a>=mod?a-mod:a;}
void NTT(int *A,int n,int f)
{
	for(int i=0;i<n;i++)if(rev[i]<i)swap(A[i],A[rev[i]]);
	for(int i=1;i<n;i<<=1)
	{
		w[0]=1;
		for(int j=1;j<i;j++)w[j]=(f==1?W[j*(N/(i<<1))]:W[N-j*(N/(i<<1))]);
		for(int j=0;j<n;j+=(i<<1))
		{
			for(int k=j;k<j+i;k++)
			{
				int x=A[k],y=1ll*w[k-j]*A[k+i]%mod;
				ad(A[k],y),A[k+i]=red(x-y+mod);
			}
		}
	}
	if(f==-1)
	{
		int iv=ksm(n,mod-2);
		for(int i=0;i<n;i++)A[i]=1ll*A[i]*iv%mod;
	}
}
int cr[xx],S[xx],T[xx];
void solve(int n,int m,int ct)
{
	make(n+m+2);
	NTT(S,N,1),NTT(T,N,1);
	for(int i=0;i<N;i++)S[i]=1ll*S[i]*T[i]%mod;
	NTT(S,N,-1);
	for(int i=1;i<=n;i++)
		cr[i]&=(S[i]==ct);
//		,cerr<<S[i]<<" "<<ct<<"#\n";
}
char t[4]={'A','G','C','T'};
signed main(){
	n=read(),m=read(),k=read();
	scanf("%s",s+1),scanf("%s",c+1);
	for(int i=1;i<=n;i++)cr[i]=1;
	for(int j=0;j<4;j++)
	{
		memset(S,0,sizeof(S)),memset(T,0,sizeof(T));
		for(int i=1;i<=n;i++)if(s[i]==t[j])S[i]=1;
		for(int i=1;i<=m;i++)if(c[i]==t[j])T[i]=1;
		int ls=k+1;
		for(int i=1;i<=n;i++)
		{
			if(S[i]==1)ls=0;
			if(ls<=k)S[i]=1;
			++ls;
		}
		ls=k+1;
		for(int i=n;i>=1;i--)
		{
			if(S[i]==1)ls=0;
			if(ls<=k)S[i]=1;
			++ls;
		}
//		for(int i=1;i<=n;i++)cout<<S[i];
//		puts("");
//		for(int i=1;i<=m;i++)cout<<T[i];
//		puts("");
		reverse(T+1,T+m+1);
		int re=0;
		for(int i=1;i<=m;i++)T[i-1]=T[i],re+=T[i];
		T[m]=0;
		solve(n,m,re);
	}
	int ans=0;
//	for(int i=m;i<=n;i++)cout<<i<<" "<<cr[i]<<"@#\n";
	for(int i=m;i<=n;i++)ans+=cr[i];
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}