#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=1e5+5;
int n,v[xx],c[xx],l[xx],r[xx];
struct node{int sum,l,r;}e[xx*28];
int root[xx],cst;
void build(int &k,int l,int r)
{
	if(!k)k=++cst;
	if(l==r)return e[k].sum=-1e9,void();
	int mid=l+r>>1;
	build(e[k].l,l,mid);
	build(e[k].r,mid+1,r);
}
int ask(int k,int l,int r,int a)
{
	if(l==r)return e[k].sum;
	int mid=l+r>>1;
	if(a<=mid)return ask(e[k].l,l,mid,a);
	return ask(e[k].r,mid+1,r,a);
}
void change(int &k,int l,int r,int a,int b)
{
	++cst,e[cst]=e[k],k=cst;
	if(l==r)return e[k].sum=b,void();
	int mid=l+r>>1;
	if(a<=mid)change(e[k].l,l,mid,a,b);
	else change(e[k].r,mid+1,r,a,b);
}
map<pair<int,int>,int>mp;
//f[xx];
signed main(){
	int tt=0;
	n=read();
	for(int i=1;i<=n;i++)v[i]=read(),c[i]=read(),l[i]=read(),r[i]=read(),mp[make_pair(l[i]+c[i],r[i])]=++tt;
	build(root[0],1,tt);
	for(int i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		if(l[i]==0)
		{
			int s=ask(root[i],1,tt,mp[make_pair(c[i],r[i])]);
			change(root[i],1,tt,mp[make_pair(c[i],r[i])],max(s,v[i]));
		}
		else 
		{
			if(mp.find(make_pair(l[i],r[i]+c[i]))!=mp.end())
			{
				int s=ask(root[i],1,tt,mp[make_pair(l[i]+c[i],r[i])]);
				change(root[i],1,tt,mp[make_pair(l[i]+c[i],r[i])],max(s,ask(root[i-1],1,tt,mp[make_pair(l[i],r[i]+c[i])])+v[i]));
			}
		}
	}
	int ans=0;
	pair<int,int> now;
	for(int i=1;i<=tt;i++)
	{
		if(r[i]==0)
		{
//			cout<<ask(root[n],1,tt,i)<<'\n';
			if(ans<ask(root[n],1,tt,i))
			{
				ans=ask(root[n],1,tt,i);
				now=make_pair(l[i]+c[i],r[i]);
			}
		}
	}
	stack<int>stk;
	for(int i=n;i>=1;i--)
	{
		if(now.first==l[i]+c[i]&&now.second==r[i])
		{
			if(!l[i]&&ask(root[i],1,tt,mp[now])==v[i]){stk.push(i);break;}
			if(ask(root[i],1,tt,mp[now])==ask(root[i-1],1,tt,mp[make_pair(l[i],r[i]+c[i])])+v[i]){stk.push(i),now=make_pair(l[i],r[i]+c[i]);continue;}
		}
	}
	cout<<stk.size()<<"\n";
	while(!stk.empty())cout<<stk.top()<<" ",stk.pop();
	puts("");
//	cout<<ans<<'\n';
	return 0;
}