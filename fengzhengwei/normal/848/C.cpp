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
int n,m;
const int xx=1e5+5;
set<int>s[xx];
int pre(set<int>::iterator it){return *--it;}
int suf(set<int>::iterator it){return *++it;}
struct nod{int op,val,id,pre,l,r;}e[xx<<3];
bool cmp1(const nod&x,const nod&y){return x.id<y.id;}
bool cmp2(const nod&x,const nod&y){return x.r<y.r;}
int lb(int x){return x&(-x);}
ll sum[xx];
void add(int x,int y){if(!x)return;for(;x<=n;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
ll ans[xx];
void cdq(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1;
	cdq(l,mid);cdq(mid+1,r);
	sort(e+l,e+mid+1,cmp1);sort(e+mid+1,e+r+1,cmp2);
	int lpos=l,rpos=mid+1;
//	cerr<<n<<" sss "<<ask(n)<<"\n";
	
	while(lpos<=mid&&rpos<=r)
	{
		if(e[lpos].id<=e[rpos].r)
		{
//			cout<<e[lpos].id<<" "<<e[rpos].r<<"\n";
			if(e[lpos].op==1)add(e[lpos].pre,e[lpos].val);
			lpos++;
		}
		else 
		{
			if(e[rpos].op==2)ans[e[rpos].id]+=ask(n)-ask(e[rpos].l-1);
			rpos++;
		}
	}
	while(lpos<=mid)
	{
//	cout<<l<<" "<<r<<"\n";
		if(e[lpos].op==1)add(e[lpos].pre,e[lpos].val);
		lpos++;
	}
	while(rpos<=r)
	{
		if(e[rpos].op==2)ans[e[rpos].id]+=ask(n)-ask(e[rpos].l-1);
		rpos++;
	}
	for(int i=l;i<=mid;i++)if(e[i].op==1)add(e[i].pre,-e[i].val);
}
int a[xx];
int tot;
void add(int op,int pre,int id,int val)
{
	tot++;
	e[tot].op=op;
	e[tot].pre=pre;
	e[tot].id=id;
	e[tot].val=val;
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)s[i].insert(0);
	tot=0;
	for(int i=1;i<=n;i++)
	{
		int c=read();
		a[i]=c;
		s[c].insert(i);
		set<int>::iterator it=s[c].find(i);
		e[++tot].op=1;
		e[tot].pre=pre(it);
		e[tot].id=i;
		e[tot].val=i-pre(it);
	}
	for(int i=1;i<=n;i++)s[i].insert(n+1),add(1,pre(s[i].find(n+1)),n+1,n+1-pre(s[i].find(n+1)));
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1)
		{
			int x,y;
			x=read();
			y=read();
			set<int>::iterator it=s[a[x]].find(x);
			add(1,pre(it),x,-(x-pre(it)));
			add(1,pre(it),suf(it),(suf(it)-pre(it)));
			add(1,x,suf(it),-(suf(it)-x));
			s[a[x]].erase(it);
			a[x]=y;
			s[a[x]].insert(x);
			it=s[a[x]].find(x);
			add(1,pre(it),x,(x-pre(it)));
			add(1,pre(it),suf(it),-(suf(it)-pre(it)));
			add(1,x,suf(it),(suf(it)-x));
		}
		else 
		{
			int x,y;
			x=read();
			y=read();
			e[++tot].op=2;
			e[tot].l=x;
			e[tot].r=y;
			e[tot].id=++cnt;
		}
	}
//	for(int i=1;i<=tot;i++)cerr<<e[i].op<<" "<<e[i].id<<" "<<e[i].pre<<" "<<e[i].val<<" "<<e[i].l<<" "<<e[i].r<<"\n";
	cdq(1,tot);
	for(int i=1;i<=cnt;i++)cout<<ans[i]<<"\n";
	return 0;
}