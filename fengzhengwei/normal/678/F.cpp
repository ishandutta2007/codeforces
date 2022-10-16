#include<bits/stdc++.h>
#define ll long long
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
const int xx=3e5+5;
int n,st[xx],ed[xx],uu[xx],vv[xx],to[xx];
struct node{ll x,y;node(){x=y=0;}node(ll a,ll b):x(a),y(b){}bool operator<(const node&w)const{return x==w.x?y<w.y:x<w.x;};};
vector<int >v[xx];// 
vector<node >s[xx<<2];// 
void cover(int k,int l,int r,int x,int y,int id)
{
	if(x<=l&&r<=y)return s[k].push_back(node(uu[id],vv[id])),void();
	int mid=l+r>>1;
	if(x<=mid)cover(k<<1,l,mid,x,y,id);
	if(mid<y)cover(k<<1|1,mid+1,r,x,y,id);
}
ll cross(node a,node b,node c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
void build(int k,int l,int r)
{
	sort(s[k].begin(),s[k].end());
	vector<node >t;
	for(int i=0;i<s[k].size();i++)
	{
		while(t.size()>1&&cross(t[t.size()-2],t[t.size()-1],s[k][i])>=0)t.pop_back();
		t.push_back(s[k][i]);
	}
	swap(s[k],t);
	if(l==r)return ;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
vector<int>w;// 
ll erf(const vector<node>&v,int now)
{
	if(!v.size())return -2e18;
	int l=0,r=v.size()-2,ans=v.size()-1;
	//-x*(c-a)>=(d-b)*y
	while(l<=r)
	{
		int mid=l+r>>1;
		if(-now*(v[mid+1].x-v[mid].x)>=(v[mid+1].y-v[mid].y))ans=mid,r=mid-1;
		else l=mid+1;
	}
	return now*v[ans].x+v[ans].y;
}
void dfs(int k,int l,int r)
{
	w.push_back(k);
	if(l==r)
	{
		if(!v[l].size())return w.pop_back(),void();
		int now=v[l][0];
		ll ans=-2e18;
		for(int i=0;i<w.size();i++)ans=max(ans,erf(s[w[i]],now));
		ans>-2e18?cout<<ans<<'\n',0:puts("EMPTY SET"),0;
		w.pop_back();
		return;
	}
	int mid=l+r>>1;
	dfs(k<<1,l,mid);
	dfs(k<<1|1,mid+1,r);
	w.pop_back();
}
int main(){
	n=read();
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		int op=read();
		if(op==1)st[++tot]=i,uu[tot]=read(),vv[tot]=read(),to[i]=tot;
		if(op==2)ed[to[read()]]=i;
		if(op==3)v[i].push_back(read());
	}
	for(int i=1;i<=tot;i++)cover(1,1,n,st[i],ed[i]+(n+1)*(!ed[i]),i);
	build(1,1,n);
	dfs(1,1,n);
	return 0;
}