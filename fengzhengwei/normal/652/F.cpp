#include<bits/stdc++.h>
#define ll long long
#define dd double
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
ll n,m,t;
const int xx=3e5+5;
struct node{ll x,id,ans,op;bool operator<(const node&w)const{return x<w.x;};}e[xx];
bool cmp(node a,node b){return a.id<b.id;}
ll ans[xx];
signed main(){
	n=read(),m=read(),t=read();
	for(int i=0;i<n;i++)
	{
		e[i].x=read()-1,e[i].id=i;
		char c;while((c=getchar())!='L'&&c!='R');
		e[i].op=c=='R'?1:-1;
	}
	sort(e,e+n);
	ll st=0;
	for(int i=0;i<n;i++)
	{
		ll to=e[i].x+e[i].op*t;
		ans[i]=(to%m+m)%m;
		to>=0?st+=to/m:st+=(to-m+1)/m;
	}
	st%=n,st+=n,st%=n;
//	cout<<st<<"\n";
	sort(ans,ans+n);
	for(int i=0;i<n;i++)e[i].ans=ans[(st+i)%n];
	sort(e,e+n,cmp);
	for(int i=0;i<n;i++)cout<<e[i].ans+1<<" ";
	puts("");
    return 0;
}