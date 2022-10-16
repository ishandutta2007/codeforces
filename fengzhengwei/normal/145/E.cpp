#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int xx=1e6+5;
int n,m;
char s[xx];
int n4[xx<<2],n7[xx<<2],mx47[xx<<2],mx74[xx<<2],rev[xx<<2];
void update(int k)
{
	n4[k]=n4[k<<1]+n4[k<<1|1];
	n7[k]=n7[k<<1]+n7[k<<1|1];
	mx47[k]=max(n4[k<<1]+n7[k<<1|1],max(mx47[k<<1]+n7[k<<1|1],n4[k<<1]+mx47[k<<1|1]));
	mx74[k]=max(n7[k<<1]+n4[k<<1|1],max(mx74[k<<1]+n4[k<<1|1],n7[k<<1]+mx74[k<<1|1]));
}
void rv(int x)
{
	swap(n4[x],n7[x]);
	swap(mx47[x],mx74[x]);
	rev[x]^=1;
}
void pd(int x){if(rev[x])rv(x<<1),rv(x<<1|1),rev[x]=0;}
void build(int k,int l,int r)
{
	if(l==r)
	{
		n4[k]+=s[l]=='4',n7[k]+=s[l]=='7';
		mx47[k]=mx74[k]=1;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	update(k);
}
void change(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return rv(k);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y);
	if(mid<y)change(k<<1|1,mid+1,r,x,y);
	update(k);
}
signed main(){
	n=read(),m=read();
	scanf("%s",s+1);
	build(1,1,n);
	while(m--)
	{
		char p[20];
		scanf("%s",p);
		if(p[0]=='s')
		{
			int l=read(),r=read();
			change(1,1,n,l,r);
		}
		else cout<<mx47[1]<<"\n";
	}
	return 0;
}