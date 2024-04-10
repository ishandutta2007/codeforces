#include<bits/stdc++.h>
#define ll long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
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
	wt(x),pc(op,0);
}
const int xx=2e5+5;
int n,m;
ll s[xx];
vector<int>v[xx];
int fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void fil(int,int);
void dec(int);
void fil(int l,int r)
{
	//cerr<<l<<" "<<r<<"@\n";
	if(l>r)swap(l,r);
	l++;//l-1,r 
	int now=l;
	while((now=find(now))<=r)
		dec(now);
}
void dec(int x){/*cerr<<x<<"@@\n";*/fa[x]=x+1;for(auto it:v[x])if(find(it)!=it)fil(x,it);}
signed main(){
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;i++)s[i]=read(),fa[i]=i;
		fa[0]=0,fa[n+1]=n+1;
		for(int i=1;i<=n;i++)s[i]-=read();
		for(int i=1;i<=n;i++)s[i]+=s[i-1];
		for(int i=0;i<=n;i++)v[i].clear();
		for(int i=1;i<=m;i++)
		{
			int l=read(),r=read();
			v[l-1].push_back(r),v[r].push_back(l-1);
		}
//		for(int i=0;i<=n;i++)cout<<s[i]<<" ";
//puts("");
		for(int i=0;i<=n;i++)if(s[i]==0)dec(i); 
		if(find(0)!=n+1)puts("NO");
		else puts("YEs");
	}
	pc('1',1);
	return 0;
}