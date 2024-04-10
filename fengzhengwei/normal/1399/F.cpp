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
int T;
const int xx=3005;
struct node{int l,r;bool operator<(const node&w)const{return r==w.r?l>w.l:r<w.r;};}e[xx];
int g[xx],f[xx],n;
const int inf=1e9;
int get(int l,int r,int L)
{
	if(l>r)return 0;
	memset(f,0,sizeof(f));
	for(int i=l;i<=r;i++)
	{
		f[i]=max(f[i],f[i-1]);
		if(e[i].l<L)continue;
		f[i]=max(f[i],g[i]+f[lower_bound(e+1,e+n+1,(node){inf,e[i].l})-e-1]);
	}
	return f[r];
}
signed main(){
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)e[i].l=read(),e[i].r=read();
		e[++n].l=0,e[n].r=2e5+1;
		sort(e+1,e+n+1);
		for(int i=1;i<=n;i++)g[i]=get(lower_bound(e+1,e+n+1,(node){inf,e[i].l})-e,i-1,e[i].l)+1;
//		for(int i=1;i<=n;i++)
//		{
//			cout<<i<<" "<<e[i].l<<" "<<e[i].r<<" "<<g[i]<<"\n";
//		}
		cout<<g[n]-1<<"\n";
	}
    return 0;
}