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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=3e5+5;
ll n,sum[4][xx],a[3][xx];
struct node{int l,r;bool operator<(const node&w)const{return l<w.l;};}l[xx];//l 
int stk[xx],top;
struct qj
{
	node e[xx];
	int sz;
	void in(int a)
	{
		sz=a;
		for(int i=1;i<=a;i++)e[i]=l[i];
	}
	void cls()
	{
		sort(e+1,e+sz+1);
		top=0;
		for(int i=1;i<=sz;i++)
		{
			while(top&&e[stk[top]].r>=e[i].r)top--;
			stk[++top]=i;
		}
//		cerr<<top<<"!@#$@#%\n";
		sz=0;
		for(int i=1;i<=top;i++)e[++sz]=e[stk[i]];
//		for(int i=1;i<=sz;i++)cout<<e[i].l<<" "<<e[i].r<<"!@#\n";
	}
	int lbd(int x){return lower_bound(e+1,e+sz+1,(node){x,0})-e;}
	//lr 
}C[4];
int f[xx];
map<ll,int>mp;
int To[xx];
int dp[2][xx],id[2][xx];//1ixdpdpid 
void trans(int a,int b,int c,int d){if(dp[a][b]<c||(dp[a][b]==c&&d<id[a][b]))dp[a][b]=c,id[a][b]=d;}
signed main(){
//	cout<<to[0][0]<<" "<<to[0][1]<<" "<<to[1][0]<<" "<<to[1][1]<<"\n";
	n=read();
	for(int i=1;i<=n;i++)a[1][i]=read();
	for(int i=1;i<=n;i++)a[2][i]=read();
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=a[i][j]+sum[i][j-1];
	for(int j=1;j<=n;j++)
		sum[3][j]=sum[1][j]+sum[2][j];
	for(int j=1;j<=3;j++)
	{
		mp.clear();
		mp[0]=0;
		int tt=0;
		for(int i=1;i<=n;i++)
		{
			if(mp.find(sum[j][i])==mp.end())
			{
				mp[sum[j][i]]=i;
				continue;
			}
			l[++tt].l=mp[sum[j][i]]+1,l[tt].r=i,mp[sum[j][i]]=i;
		}
		C[j].in(tt);
	}
	C[1].cls();
	C[2].cls();
	C[3].cls();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=1;j++)
		{
//			cout<<i<<" "<<j<<" "<<dp[j][i]<<"!!\n";
			if(j==0)
			{
				int to=C[1].lbd(i+1);
				if(to!=C[1].sz+1)
					// 
					trans(0,C[1].e[to].r,dp[j][i]+1,id[j][i]);
				to=C[2].lbd(id[j][i]+1);
					//() 
				if(to!=C[2].sz+1&&C[2].e[to].r>=i)// 
					trans(1,C[2].e[to].r,dp[j][i]+1,i);
				to=C[3].lbd(i+1);
				if(to!=C[3].sz+1)
					// 
					trans(0,C[3].e[to].r,dp[j][i]+1,C[3].e[to].r),
					trans(1,C[3].e[to].r,dp[j][i]+1,C[3].e[to].r);
			}
			else 
			{
				int to=C[2].lbd(i+1);
				if(to!=C[2].sz+1)
					// 
					trans(1,C[2].e[to].r,dp[j][i]+1,id[j][i]);
				to=C[1].lbd(id[j][i]+1);
					//() 
				if(to!=C[1].sz+1&&C[1].e[to].r>=i)
					trans(0,C[1].e[to].r,dp[j][i]+1,i);
				to=C[3].lbd(i+1);
				if(to!=C[3].sz+1)
					// 
					trans(0,C[3].e[to].r,dp[j][i]+1,C[3].e[to].r),
					trans(1,C[3].e[to].r,dp[j][i]+1,C[3].e[to].r);
			}
		}
	}
	int ans=-1e9;
	for(int i=0;i<=n;i++)
	{
//			cout<<i<<" "<<dp[i][j]<<" "<<id[i][j]<<"!!!\n";
		ans=max(ans,dp[0][i]);
		ans=max(ans,dp[1][i]);
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}