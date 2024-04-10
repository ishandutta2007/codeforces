// LUOGU_RID: 91571992
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
int n,q,ct[xx];
struct nod
{
	int l,r,id;
	bool operator<(const nod&w)const{return l<w.l;}
}e[xx<<1];
int lb(int x){return x&-x;}
ll sum[xx];
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
void add(int x,ll y){for(;x<=n;x+=lb(x))sum[x]+=y;}
ll c_2(ll n){return n<0?0:n*(n-1)/2;}
ll c_3(ll n){return n*(n-1)*(n-2)/6;}
vector<int>v[xx];
ll ans[xx];
int main(){
//	freopen("a.in","r",stdin);
	q=read();
	for(int i=1;i<=q;i++)e[i].l=read(),e[i].r=read(),e[i].id=i,n=max(n,e[i].r);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)ct[j]++;
	sort(e+1,e+q+1);
	for(int i=1;i<=n;i++)
	{
		add(i,c_2(ct[i]-1));
		if(i%3==0)
		{
			if(i%5==0)add(i,1),v[i/5*2].push_back(i);
			if(i%2==0)add(i,1),v[i/2].push_back(i);
		}
	}
	int ls=1;
	for(int i=1;i<=q;i++)
	{
		while(ls<=e[i].l-1)
		{
			for(auto it:v[ls])add(it,-1);
			for(int j=ls;j<=n;j+=ls)
				add(j,c_2(ct[j]-2)-c_2(ct[j]-1)),--ct[j];
			++ls;
		}
//		cerr<<c_3(e[i].r-e[i].l+1)<<" "<<e[i].r-e[i].l+1<<" "<<ask(e[i].r)<<" "<<ct[3]<<" "<<ct[4]<<" "<<ct[5]<<"#\n";
		ans[e[i].id]=c_3(e[i].r-e[i].l+1)-ask(e[i].r);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}



}signed main(){return ifzw::main();}