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
const int xx=1e5+5;
int fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int to[xx];
signed main(){
	int n=read();
	if(n&1)
		puts("-1"),exit(0);
	for(int i=0;i<n;i++)fa[i]=i;
	for(int i=0;i<n;i++)if(i>=n/2)to[i]=(i+i+1)%n,fa[find(i)]=find(to[i]);else to[i]=(i+i)%n,fa[find(i)]=find(to[i]);
	for(int i=0;i<n/2;i++)if(find(i)!=find(i+n/2))swap(to[i],to[i+n/2]),fa[find(i)]=i+n/2;
//	,cerr<<"!!!!\n";
	int x=0;
//	cerr<<find(1)<<"!!\n";
	while(to[x])cout<<x<<" ",x=to[x];
	cout<<x<<" "<<0<<"\n";
	pc('1',1);
	return 0;
}