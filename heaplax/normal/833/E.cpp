#include<bits/stdc++.h>
#define N 300001
#define M 1<<20
using namespace std;
struct node{int l,r,c;bool operator < (const node &i)const{return c<i.c;}}e[N];
struct node2{bool type;int pos,id;bool operator < (const node2 &i)const{return pos<i.pos;}}p[N+N],w[N];
int n,m,q,C,ans[N],opt[N],num[N],val[N],single[N];
map<pair<int,int>,int> f;set<int> s;
int l[M],r[M],mx[M];
void build(int k,int a,int b)
{
	l[k]=a;r[k]=b;
	if(a==b)return;
	build(k<<1,a,a+b>>1);
	build(k<<1|1,(a+b>>1)+1,b);
}
void modify(int k,int a,int b)
{
	if(l[k]==r[k])
	{
		mx[k]=b;
		return;
	}
	int m=l[k]+r[k]>>1;
	if(a<=m)modify(k<<1,a,b);
	else modify(k<<1|1,a,b);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
int query(int k,int a,int b)
{
	if(b<a)return 0;
	if(a<=l[k] && b>=r[k])return mx[k];
	int m=l[k]+r[k]>>1;
	if(b<=m)return query(k<<1,a,b);
	else if(a>m)return query(k<<1|1,a,b);
	else return max(query(k<<1,a,b),query(k<<1|1,a,b));
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>C;
	for(int i=1;i<=n;++i)
		cin>>e[i].l>>e[i].r>>e[i].c;
	sort(e+1,e+n+1);
	for(int i=1;i<=n;++i)
	{
		p[++m].pos=e[i].l;p[m].id=i;
		p[++m].pos=e[i].r;p[m].id=i;p[m].type=1;
	}
	cin>>q;
	for(int i=1;i<=q;++i)
	{
		cin>>w[i].pos;
		w[i].id=i;
		if(!n)cout<<w[i].pos<<endl;
	}
	if(!n)return 0;
	sort(p+1,p+m+1);
	sort(w+1,w+q+1);
	for(int i=1;i<=n;++i)val[i]=e[i].c;
	for(int i=1;i<=n;++i)
		num[i]=upper_bound(val+1,val+n+1,C-e[i].c)-val-1;
	build(1,1,n);
	int last=0,cur,free=0,top=0;
	for(int i=1,j=1;i<=m;++i)
	{
		cur=p[i].pos;
		int t=cur-last;
		if(s.empty())free+=t;
		else if(s.size()==1)
		{
			int u=*s.begin();
			if(val[u]<=C)
			{
				single[u]+=t;
				opt[u]+=t;
				if(num[u]<u)opt[u]=max(opt[u],single[u]+query(1,1,num[u]));
				else opt[u]=max(opt[u],single[u]+max(query(1,1,u-1),query(1,u+1,num[u])));
				top=max(top,opt[u]);
				modify(1,u,single[u]);
			}
		}
		else if(s.size()==2)
		{
			int u=*s.begin(),v=*next(s.begin());
			if(val[u]+val[v]<=C)
			{
				if(u>v)swap(u,v);
				int now=(f[make_pair(u,v)]+=t)+single[u]+single[v];
				opt[u]=max(opt[u],now);
				opt[v]=max(opt[v],now);
				top=max(top,now);
			}
		}
		for(;j<=q && top+free>=w[j].pos;++j)
			ans[w[j].id]=p[i].pos-(top+free-w[j].pos);
		if(p[i].type==0)s.insert(p[i].id);
		else s.erase(p[i].id);
		last=cur;
		for(;j<=q&&i==m;++j)
			ans[w[j].id]=p[i].pos-(top+free-w[j].pos);
	}
	for(int i=1;i<=q;++i)
		cout<<ans[i]<<endl;
}