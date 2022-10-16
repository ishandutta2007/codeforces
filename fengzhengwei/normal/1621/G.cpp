#include<bits/stdc++.h>
#define ll long long
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
const int xx=2e5+5;
const int mod=1e9+7;
int a[xx],f[xx],sum[xx],n;
int lb(int x){return x&-x;}
void add(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y,sum[x]%=mod;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x],ans%=mod;return ans;}
int ls[xx],stk[xx];
vector<int>v[xx];
int g[xx],ans;
void solve(vector<int>&s)
{
	//lis 
//	assert(ask(n)==0);
	for(auto it:s)
	{
//		if(it==1)
//		{
//			cout<<ask(n)<<" qq "<<ask(a[it])<<"\n";
//		}
		g[it]=ask(n)-ask(a[it])+1+mod,g[it]%=mod,add(a[it],g[it]);
		ans+=mod-1ll*g[it]*f[it]%mod,ans%=mod;
	}
	for(auto it:s)add(a[it],-g[it]);
}
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=ls[i]=read();
		sort(ls+1,ls+n+1);
		int tt=unique(ls+1,ls+n+1)-ls-1;
		for(int i=1;i<=n;i++)a[i]=lower_bound(ls+1,ls+tt+1,a[i])-ls;
		memset(sum,0,sizeof(sum[0])*(n+1));
		ans=0;
		for(int i=1;i<=n;i++)f[i]=(ask(a[i]-1)+1)%mod,add(a[i],f[i]);// 
//		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)v[i].clear();
		memset(sum,0,sizeof(sum[0])*(n+1));
		for(int i=1;i<=n;i++)g[i]=(ask(a[i]-1)+f[i])%mod,add(a[i],g[i]),ans+=g[i],ans%=mod;// 
//		cout<<ans<<"\n";
		memset(sum,0,sizeof(sum[0])*(n+1));
		int top=0;
		for(int i=n;i>=1;i--)
		{
			if(!top||a[stk[top]]<a[i])
			{
				stk[++top]=i;
				ans+=mod-f[i],ans%=mod;
//				v[i].push_back(i);// 
			}
			else 
			{
				if(a[i]==a[stk[top]])ans+=mod-f[i],ans%=mod;
				else 
				{
					int l=1,r=top,ans=0;
					while(l<=r)
					{
						int mid=l+r>>1;
						if(a[stk[mid]]>a[i])ans=mid,r=mid-1;
						else l=mid+1;
					}
					v[stk[ans]].push_back(i);
				}
			}
		}
//		cout<<ans<<"!!\n";
		for(int i=1;i<=n;i++)
			if(v[i].size())solve(v[i]);
//		for(int i=1;i<=n;i++)cout<<i<<" "<<g[i]<<"\n";
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}