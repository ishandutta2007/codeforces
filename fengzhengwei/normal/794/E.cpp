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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
//15.44
const int xx=3e5+5;
int mx[xx<<2],mx1[xx<<2],a[xx];
void build(int k,int l,int r)
{
	if(l==r)return mx[k]=a[l],mx1[k]=(a[l]<=a[l-1]||a[l]<=a[l+1])?a[l]:0,void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
	mx1[k]=max(mx1[k<<1],mx1[k<<1|1]);
}
int ask(int k,int l,int r,int x,int y,int op)
{
	if(x>y)return 0;
	if(x<=l&&r<=y)return op==0?mx[k]:mx1[k];
	int mid=l+r>>1,ans=0;
	if(x<=mid)ans=max(ans,ask(k<<1,l,mid,x,y,op));
	if(mid<y)ans=max(ans,ask(k<<1|1,mid+1,r,x,y,op));
	return ans;
}
int n;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	for(int k=0;k<n;k++)
	{
		if(k==n-1)cout<<ask(1,1,n,1,n,0)<<"\n",exit(0);
		if((n-k-1)&1)//max 
		{
			int nows=(n-k-1);
			int re=(nows-1)/2;//-10 
//			cout<<re<<" "<<n<<" "<<k<<"!!!\n";
			cout<<ask(1,1,n,1+re,n-re,0)<<"\n";
		}
		else //min 
		{
			int nows=(n-k-1);
			int re=(nows-1)/2;//-10 
			int ans=ask(1,1,n,1+re+1,n-re-1,1);
			if(a[1+re]<=a[1+re+1])ans=max(ans,a[1+re]);
			if(a[n-re]<=a[n-re-1])ans=max(ans,a[n-re]);
			cout<<ans<<"\n";
		}
	}
	pc('1',1);
	return 0;
}