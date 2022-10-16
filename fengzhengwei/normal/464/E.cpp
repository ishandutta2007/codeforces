#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
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
namespace edge
{
	struct node{int next,to,v;}e[xx<<1];
	int cnt,h[xx];
	void add(int x,int y,int z)
	{
		cnt++;
		e[cnt].next=h[x];
		h[x]=cnt;
		e[cnt].to=y;
		e[cnt].v=z;
	}
}
const int base1=233,base2=511;
const int mod=1e9+7;
ull kb1[xx];
ll kb2[xx],kb3[xx];
int red(int x){return x>=mod?x-mod:x;}
//nod hash 
struct nod{ull a;ll b;nod operator+(const nod&w)const{return (nod){a+w.a,red(b+w.b)};};bool operator==(const nod&w)const{return a==w.a&&b==w.b;};};
//no  
struct no
{
	nod hs;
	int l,r;
	int sum;
}e[xx*64];//(log)() 
int cst;
stack<int>stk;
void update(int k){e[k].hs=e[e[k].l].hs+e[e[k].r].hs,e[k].sum=e[e[k].l].sum+e[e[k].r].sum;}
int get()
{
	if(!stk.size())return ++cst;
	int s=stk.top();
	stk.pop();
	return s;
}
vector<int>v;// 
void cover(int &k,int l,int r,int x,int y)// 
{
	int o=get();e[o]=e[k],k=o;
	v.push_back(o);
	if(!k||x>y)return;
	if(x<=l&&r<=y)return k=0,void();
	int mid=l+r>>1;
	if(x<=mid)cover(e[k].l,l,mid,x,y);
	if(mid<y)cover(e[k].r,mid+1,r,x,y);
	update(k);
}
void insert(int &k,int l,int r,int x)
{
	int o=get();e[o]=e[k],k=o;
	v.push_back(o);
	if(l==r)return e[k].hs=(nod){kb1[l],kb2[l]},e[k].sum=1,void();
	int mid=l+r>>1;
	if(x<=mid)insert(e[k].l,l,mid,x);
	else insert(e[k].r,mid+1,r,x);
	update(k);
}
int ask(int k,int l,int r,int x)
{
	if(!k)return 0;
	if(l==r)return 1;// 
	int mid=l+r>>1;
	if(x<=mid)return ask(e[k].l,l,mid,x);
	return ask(e[k].r,mid+1,r,x);
}
int erf(int a,int b,int l,int r)
{
	if(e[a].hs==e[b].hs)return l-1;
	if(l==r)return l;
	int mid=l+r>>1;
//	cout<<e[e[a].r].hs.a<<" "<<e[e[b].r].hs.a<<" "<<mid<<"\n";
	if(e[e[a].r].hs==e[e[b].r].hs)return erf(e[a].l,e[b].l,l,mid);
	return erf(e[a].r,e[b].r,mid+1,r);
}
int get(int k,int l,int r,int x)//x1 
{
	if(l==r)return e[k].sum;
	int mid=l+r>>1;
	if(mid<x)return get(e[k].r,mid+1,r,x);
	int w=get(e[k].l,l,mid,x);
	if(w==mid-max(x,l)+1)return w+get(e[k].r,mid+1,r,x);
	return w;
}
struct nm//num 
{
	int rt,vs;
	vector<int>p;
	bool operator<(const nm&w)const //sort 
	{
		int o=erf(rt,w.rt,0,1e5);
//		cout<<o<<" "<<ask(rt,0,1e5,2 )<<" "<<ask(w.rt,0,1e5,2)<<"QWWWE\n";
		if(o==-1)return 0;
		return ask(rt,0,1e5,o)<ask(w.rt,0,1e5,o);
	}
	void add(int x)//x1 
	{
		v.clear();
		p.clear();
//		cout<<"qweq"
		int o=get(rt,0,1e5,x);
		if(o)cover(rt,0,1e5,x,x+o-1);
		insert(rt,0,1e5,x+o);
		swap(v,p);
	}
	void clear()//dijkistrannlog 
	{
		for(int i=0;i<p.size();i++)stk.push(p[i]);
		p.clear();
	}
}ds[xx];
struct nd// 
{
	int dis;
	int x;
	bool operator<(const nd&w)const// 
	{
		int o=erf(dis,w.dis,0,1e5);
		if(o==-1)return 0;
		return ask(dis,0,1e5,o)>ask(w.dis,0,1e5,o);
	}
};
priority_queue<nd>q;
int s,t;
int pre[xx],vis[xx],val[xx];
#define ed edge::
void getans(int x,ll va,int dp)
{
	if(x==s)
	{
		cout<<va<<"\n";
		cout<<dp<<"\n";
		cout<<x<<" ";
		return;
	}
//	cout<<val[x]<<"asdsad\n";
	getans(pre[x],red(va+kb3[val[x]]),dp+1);
	cout<<x<<" ";
}
void dij()
{
	ds[s].vs=1;
	q.push((nd){ds[s].rt,s});
	while(!q.empty())
	{
		int x=q.top().x;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		nm ls;
//		cout<<x<<"sss \n";
		for(int i=ed h[x];i;i=ed e[i].next)
		{
			ls=ds[x];
//		cout<<"x="<<x<<"\n";
			ls.add(ed e[i].v);
//			cout<<(ls<ds[ed e[i].to])<<" "<<e[ls.rt].sum<<" "<<e[ls.rt].hs.a<<" "<<e[ds[ed e[i].to].rt].hs.a<<"\n";
			if(!ds[ed e[i].to].vs||ls<ds[ed e[i].to])
			{
//				ds[ed e[i].to].clear();// 
				ds[ed e[i].to]=ls;
//				cout<<x<<" "<<ed e[i].to<<" "<<ed e[i].v<<"\n";
				pre[ed e[i].to]=x;
				val[ed e[i].to]=edge::e[i].v;
				if(!vis[ed e[i].to])q.push((nd){ds[ed e[i].to].rt,ed e[i].to});
			}
			else ls.clear();
		}
	}
	if(!ds[t].vs)return puts("-1"),void();
	getans(t,0,1);
	puts("");
}
int main(){
	kb1[0]=1;kb2[0]=1;kb3[0]=1;
	for(int i=1;i<=1e5;i++)kb1[i]=kb1[i-1]*base1,kb2[i]=kb2[i-1]*base2%mod,kb3[i]=red(kb3[i-1]*2);
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		a=read();
		b=read();
		c=read();
		edge::add(a,b,c);
		edge::add(b,a,c);
	}
	s=read();t=read();
	dij();
	return 0;
}