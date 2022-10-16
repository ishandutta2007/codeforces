#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=8e5+5;
int n,L;
ll a[xx],b[xx];
ll get(ll a){return upper_bound(b+1,b+n+n+n+n+1,a)-b-1;}
struct nod{int id;ll v;}q[xx];
bool check(ll mid)
{
	int l=1,r=0;
	for(int i=n+1;i<=n+n+n;i++)
//	mx=-1e9;
	{
		nod now={i,get(a[i]-mid-1)-i};
		while(l<=r&&q[l].id<=i-n)l++;
		while(l<=r&&q[r].v<=now.v)r--;
		q[++r]=now;
//		mx=max(mx,get(a[i]-mid-1)-i);
		if(get(a[i]+mid)-i-q[l].v<1)return 0;
	}
	return 1;
}
signed main(){
	n=read(),L=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(int i=n+1;i<=n+n+n+n;i++)a[i]=a[i-n]+L;
	for(int i=n+1;i<=n+n+n+n;i++)b[i]=b[i-n]+L;
	ll l=0,r=L,ans=0;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}