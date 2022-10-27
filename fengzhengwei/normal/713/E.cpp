// LUOGU_RID: 90204321
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long
#define LL __int128
#define ull unsigned ll 
#define dd double
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
char ST;
const int xx=1e6+5;
int n,m,a[xx],b[xx];
int dist(int x,int y)
{
	if(x>y)return (m+y-x);
	return y-x;
}
int dp[xx];
bool check(int mid)
{
	for(int i=1;i<=n;i++)dp[i]=0;
	dp[1]=a[1];//1 <-
	for(int i=2;i<=n;i++)
	{
		if(dp[i-1]>=a[i]-1)dp[i]=a[i]+mid;
		else 
		{
			if(i!=2&&dp[i-2]>=a[i]-mid-1)dp[i]=max(a[i],a[i-1]+mid);// 
			else if(dp[i-1]>=a[i]-mid-1)dp[i]=a[i];
			else break;
		}
//		if(i>=1e4)cerr<<dp[i]<<" "<<a[i]<<" "<<a[i+1]<<" "<<i<<"!\n";
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	puts("");
//	cerr<<dp[n]<<" "<<a[1]-mid+m-1<<"@\n";
	if(dp[n]>=a[1]-mid+m-1)return 1;
	for(int i=1;i<=n;i++)dp[i]=0;
	dp[1]=dp[2]=a[1]+mid;//1 -> 2 <-
	for(int i=3;i<=n;i++)
	{
		if(dp[i-1]>=a[i]-1)dp[i]=a[i]+mid;
		else 
		{
			if(i!=3&&dp[i-2]>=a[i]-mid-1)dp[i]=max(a[i],a[i-1]+mid);
			else if(dp[i-1]>=a[i]-mid-1)dp[i]=a[i];
			else break;
		}
	}
//	cerr<<dp[n]<<" "<<a[2]-mid+m-1<<"@\n";
	if(dp[n]>=a[2]-mid+m-1)return 1;
	return 0;
}
char ED;
int main(){
	cerr<<abs(&ST-&ED)/1024/1024<<"\n";
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	m=read(),n=read();
	if(n==1)cout<<m-1<<"\n",exit(0);
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i];
	unique(b+1,b+n+1);
	int cr=1;
	for(int i=1;i<=min(n,m);i++)cr&=(b[i]!=i);
	if(cr&&(m<=n))puts("0"),exit(0);
	a[n+1]=a[1];
	int mx=0,Mid=0;
	for(int i=1;i<=n;i++)
		if(mx<dist(a[i],a[i+1]))mx=dist(a[i],a[i+1]),Mid=i+1;
	if(Mid==n+1)Mid=1;
	int D=a[Mid]-1;
	for(int i=1;i<=n;i++)a[i]-=D,(a[i]<=0?a[i]+=m:0);
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	puts("");
	rotate(a+1,a+Mid,a+n+1);
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	puts("");
//	cout<<check(7209)<<"#\n";
//	return 0;
	int l=0,r=mx-2,ans=mx-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}