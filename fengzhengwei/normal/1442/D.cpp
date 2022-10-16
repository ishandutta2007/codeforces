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
const int xx=3000+5;
int n,m,a[xx][xx],sz[xx];
ll sum[xx];
vector<int>v[xx<<2];
struct nod{ll v[xx];};
void ins(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return;
	if(x<=l&&r<=y)return v[k].push_back(z),void();
	int mid=l+r>>1;
	if(x<=mid)ins(k<<1,l,mid,x,y,z);
	if(mid<y)ins(k<<1|1,mid+1,r,x,y,z);
}
ll ans;
nod cur;
void ask(int k,int l,int r)
{
	nod now=cur;
	for(auto it:v[k])
	{
//		cout<<l<<" "<<r<<" "<<it<<" "<<sum[it]<<" qq "<<sz[it]<<"!!\n";
		for(int i=m;i>=sz[it];i--)
			cur.v[i]=max(cur.v[i],cur.v[i-sz[it]]+sum[it]);
	}
	if(l==r)
	{
		ll S=0;
//		for(int i=0;i<=m;i++)cout<<cur.v[i]<<"\n";
//		puts("");
		for(int i=0;i<=sz[l];i++)
		{
			if(i)S+=a[l][i];
			ans=max(ans,S+cur.v[m-i]);
		}
		cur=now;
		return;
	}
	int mid=l+r>>1;
	ask(k<<1,l,mid);
	ask(k<<1|1,mid+1,r);
	cur=now;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		ins(1,1,n,1,i-1,i),ins(1,1,n,i+1,n,i);
	for(int i=1;i<=n;i++)
	{
		int r=read();
		sz[i]=min(r,m);
		for(int j=1;j<=min(r,m);j++)a[i][j]=read(),sum[i]+=a[i][j];
		for(int j=m+1;j<=r;j++)read();
	}
	ask(1,1,n);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}