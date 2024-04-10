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
const int xx=1e5+5,mod=998244353,base=2011111;
char s[xx];
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
void pre()
{
	pw[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i-1]*base%mod;
	ni[1]=ksm(base,mod-2);ni[0]=1;
	for(int i=2;i<xx;i++)ni[i]=ni[i-1]*ni[1]%mod;
}
ll sum[xx];
int n;
void pre1(){for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i]*pw[i],sum[i]%=mod;}
ll get(int l,int r){return r>n?-1:(sum[r]-sum[l-1]+mod)*ni[l]%mod;}
int lcp(int L,int R)
{
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(L+mid-1<=n&&R+mid-1<=n&&get(L,L+mid-1)==get(R,R+mid-1))ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int lcs(int L,int R)
{
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(L-mid+1>=1&&R-mid+1>=1&&get(L-mid+1,L)==get(R-mid+1,R))ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int vis[xx],ban[xx];
void run(int len)
{
	s[n+1]=0;
//	cout<<(s+1)<<"\n";
//	cerr<<len<<"!!\n";
	int lst=0;
	for(int i=1;i<=n;i+=len)
	{
		if(i+len>n)break;
		int T=lcp(i,i+len),S=lcs(i,i+len);
		if(!T)continue;
		int tl=max(lst+1,i-S+1),tr=i+T-1;
//		if(len==2)cout<<i<<" "<<T<<" "<<S<<" "<<s+1<<" "<<tl<<" "<<tr<<" "<<lst<<"\n";
		if(tr-tl+1>=len)lst=tl+len-1,vis[tl]=1;
	}
	if(lst==0)return;
	for(int i=1;i<=n;i++)ban[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			for(int j=1;j<=len;j++)ban[i+j-1]=1;
		vis[i]=0;
	}
	int tt=0;
	for(int i=1;i<=n;i++)
		if(!ban[i])s[++tt]=s[i];
	n=tt;
	pre1();
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	pre(),pre1();
//	cout<<lcp(1,2)<<"\n";
	for(int i=1;i<=n;i++)run(i);
	s[n+1]=0;
	cout<<(s+1)<<"\n";
	pc('1',1);
	return 0;
}