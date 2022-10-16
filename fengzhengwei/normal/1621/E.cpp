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
const int mod=998244353;
int a[xx];
char s[xx];
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
int n,m,q,k,tt;
int mn[xx<<2],adt[xx<<2];
vector<int>v[xx];
void build(int k,int l,int r)
{
	adt[k]=0;
	if(l==r)return mn[k]=(n-l+1),void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
void ad(int k,int v){mn[k]+=v,adt[k]+=v;}
void pd(int k){if(ad[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
void cg(int k,int l,int r,int x,int y,int v)
{
	if(x<=l&&r<=y)return ad(k,v);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,v);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,v);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
int get(ll sum,ll sz)
{
	int l=1,r=n,ans=n+1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(a[mid]*sz>=sum)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
ll ysum[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		build(1,1,n+1);//ab 
		for(int i=1;i<=m;i++)
		{
			v[i].clear();
			k=read();
			ll sum=0;
			while(k--)v[i].push_back(read()),sum+=*--v[i].end();
			int s=get(sum,v[i].size());
			cg(1,1,n+1,1,s,-1);
			ysum[i]=sum;
		}
		for(int i=1;i<=m;i++)
		{
			ll sum=ysum[i];
			int s=get(sum,v[i].size());
			cg(1,1,n+1,1,s,1);// 
			for(auto it:v[i])
			{
				sum-=it;
				s=get(sum,v[i].size()-1);
				cg(1,1,n+1,1,s,-1);
				if(mn[1]>=0)cout<<1;
				else cout<<0;
				sum+=it;
				cg(1,1,n+1,1,s,1);
			}
			s=get(sum,v[i].size());
			cg(1,1,n+1,1,s,-1);
		}
		puts("");
		
	}
	pc('1',1);
	return 0;
}