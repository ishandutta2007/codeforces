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
int n,m,q,k;
struct node
{
	int l,r,v;
}e[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)e[i].l=read(),e[i].r=read(),e[i].v=read();
		int mn=2e9,mx=-2e9,ans=1e9;
		multiset<int>F,E;
		for(int i=1;i<=n;i++)
		{
			if(e[i].l<mn&&e[i].r>mx)
			{
				mn=e[i].l,mx=e[i].r;
				ans=e[i].v;
				F.clear(),E.clear();
				F.insert(e[i].v);
				E.insert(e[i].v);
			cout<<ans<<"\n";
				continue;
			}
			if(e[i].l<mn)
			{
				mn=e[i].l;
				F.clear();F.insert(e[i].v);
				if(e[i].r==mx)ans=e[i].v,E.insert(e[i].v);
				else ans=e[i].v+*E.begin();
			cout<<ans<<"\n";
				continue;
			}
			if(e[i].r>mx)
			{
				mx=e[i].r;
				E.clear();E.insert(e[i].v);
				if(e[i].l==mn)ans=e[i].v,F.insert(e[i].v);
				else ans=e[i].v+*F.begin();
			cout<<ans<<"\n";
				continue;
			}
			if(e[i].r==mx&&e[i].l==mn)
			{
				ans=min(ans,e[i].v);
				E.insert(e[i].v);
				F.insert(e[i].v);
			cout<<ans<<"\n";
				continue;
			}
			if(e[i].r==mx)
			{
				ans=min(ans,e[i].v+*F.begin());
				E.insert(e[i].v);
			cout<<ans<<"\n";
				continue;
			}
			if(e[i].l==mn)
			{
				ans=min(ans,e[i].v+*E.begin());
				F.insert(e[i].v);
			cout<<ans<<"\n";
				continue;
			}
			cout<<ans<<"\n";
		}
	}
	pc('1',1);
	return 0;
}