#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc()
{
	static char buf[1<<16],*s,*t;
	if(s==t)
	{
		t=(s=buf)+fread(buf,1,1<<16,stdin);
		if(s==t)return EOF;
	}
	return *s++;
}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,k;
const int xx=1e5+5;
struct node{int x,r,f,ls,rs;}e[xx],t[xx];
int lsh[xx<<2],tot;
bool cmp1(const node&a,const node&b)
{
	if(a.r!=b.r)return a.r>b.r;
	if(a.f!=b.f)return a.f<b.f;
	return a.x<b.x;
}
int sum[xx<<2];
int lb(int x){return x&(-x);}
void add(int x,int y){for(;x<=tot;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
ll ans;
void cdq(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1;
	cdq(l,mid);cdq(mid+1,r);
	int lpos=l,rpos=l-1;
	for(int i=mid+1;i<=r;i++)// 
	{
		while(rpos<mid&&e[rpos+1].f<=e[i].f+k)add(e[++rpos].x,1);
		while(lpos<=rpos&&e[lpos].f<e[i].f-k)add(e[lpos].x,-1),lpos++;
		ans+=ask(e[i].rs)-ask(e[i].ls);
	}
	int tot=l-1;
	while(lpos<=rpos)add(e[lpos].x,-1),lpos++;
	lpos=l,rpos=mid+1;
	while(lpos<=mid&&rpos<=r)// 
	{
		if(e[lpos].f<=e[rpos].f)t[++tot]=e[lpos++];
		else t[++tot]=e[rpos++];
	}
	while(lpos<=mid)t[++tot]=e[lpos++];
	while(rpos<=r)t[++tot]=e[rpos++];
	for(int i=l;i<=r;i++)e[i]=t[i];
}
signed main(){
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		e[i].x=read();
		e[i].r=read();
		lsh[++tot]=e[i].x;//x,x+r,x-r-1 
		lsh[++tot]=e[i].x+e[i].r;
		lsh[++tot]=e[i].x-e[i].r-1;
		e[i].f=read();
	}
//	cout<<tot<<"\n";
	sort(lsh+1,lsh+tot+1);
	tot=unique(lsh+1,lsh+tot+1)-lsh-1;
	sort(e+1,e+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		e[i].ls=lower_bound(lsh+1,lsh+tot+1,e[i].x-e[i].r-1)-lsh;
		e[i].rs=lower_bound(lsh+1,lsh+tot+1,e[i].x+e[i].r)-lsh;
		e[i].x=lower_bound(lsh+1,lsh+tot+1,e[i].x)-lsh;
//		cout<<e[i].x<<" "<<e[i].ls<<" "<<e[i].rs<<" "<<e[i].r<<" "<<e[i].f<<"\n";
	}
	cdq(1,n);
	cout<<ans<<"\n";
	return 0;
}