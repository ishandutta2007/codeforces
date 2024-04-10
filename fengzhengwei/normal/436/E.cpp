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
int n,m;
const int xx=6e5+5;
struct node
{
	int a,b,id;
	bool operator<(const node&w)const{return b<w.b;}
}e[xx];
struct nod
{
	ll sum;
	int size,l,r;
}t[xx*17];
#define e t
int cst,root;
void insert(int &k,int l,int r,int x,int op)
{
	if(!k)k=++cst;
	e[k].size+=op;
	e[k].sum+=op*x;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)insert(e[k].l,l,mid,x,op);
	else insert(e[k].r,mid+1,r,x,op);
}
ll ask(int k,int l,int r,int x)
{
	if(!x)return 0;
	if(e[k].size<=x)return e[k].sum;
	if(l==r)return 1ll*l*x;
	int mid=l+r>>1;
	if(e[e[k].l].size>x)return ask(e[k].l,l,mid,x);
	return ask(e[k].l,l,mid,x)+ask(e[k].r,mid+1,r,x-e[e[k].l].size);
}
#undef e
int an[xx];
int re[xx];
signed main(){
//	cout<<sizeof(t)/1024/1024<<"\n";
	n=read(),m=read();
	for(int i=1;i<=n;i++)e[i].a=read(),e[i].b=read(),e[i].id=i;
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)insert(root,1,1e9,e[i].a,1);
	for(int i=1;i<=n;i++)insert(root,1,1e9,1e9,1);
	ll ans=1e18;
	ll res=0,tt=0;
	int id=0;
	for(int i=0;i<=n;i++)
	{
		if(i)insert(root,1,1e9,e[i].a,-1);
		if(i)tt+=2,res+=e[i].b;
		if(tt<=m)
		{
			ll o=res+ask(root,1,1e9,m-tt);
//			cout<<o<<'\n';
			if(ans>o)ans=o,id=i;
		}
		if(i)tt--,res-=e[i].b-e[i].a;
		if(i)insert(root,1,1e9,e[i].b-e[i].a,1);
	}
	cout<<ans<<"\n";
	multiset<pair<int,int> >s;
	an[id]=2;
	for(int i=1;i<id;i++)
	{
		an[i]=1;
		s.insert(make_pair(e[i].b-e[i].a,i));
	}
	tt=id?id+1:0;
	for(int i=id+1;i<=n;i++)
	{
		an[i]=0;
		s.insert(make_pair(e[i].a,i));
	}
	tt=m-tt;
	while(tt--)
	{
		an[s.begin()->second]++;
		s.erase(s.begin());
	}
	for(int i=1;i<=n;i++)re[e[i].id]=an[i];
	for(int i=1;i<=n;i++)cout<<re[i];
	puts("");
	return 0;
}