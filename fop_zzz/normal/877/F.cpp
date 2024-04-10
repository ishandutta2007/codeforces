#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define pb push_back
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
map<ll,int> mp;
int v[400001],lst[400001],nxt[400001],t[400001],n,k,m;
ll ans;
struct node{int L,R,bl,br,n,num;ll ans;}	que[400001];
inline bool cmp(node x,node y){return x.bl!=y.bl?x.bl<y.bl:x.br<y.br;}
ll s[400001];
inline void change(int x,int del,int LR)
{
	if(del==-1)	v[s[x]]--;
	if(LR==1)
		ans+=v[lst[x]]*del;
		else	ans+=v[nxt[x]]*del;
	if(del==1)	v[s[x]]++;
}
inline void MO()
{
	int l=1,r=0;
	For(i,1,m)
	{
		while(r<que[i].R){r++;change(r,1,1);}
		while(r>que[i].R){change(r,-1,1);r--;}
		while(l<que[i].L){change(l,-1,2);l++;}
		while(l>que[i].L){l--;change(l,1,2);}
		que[i].ans=ans+v[nxt[l-1]];//cout<<v[nxt[l-1]]<<endl;
	}
}
ll q[500001],top,tot;
inline bool cmp1(node x,node y){return x.num<y.num;}
int main()
{
	n=read();k=read();
	For(i,1,n)	t[i]=read();
	For(i,1,n)
	{
		ll x=read();
		s[i]=s[i-1]+x*(t[i]==1?1:-1);
	}
	For(i,1,n)	q[++top]=s[i],q[++top]=s[i]+k,q[++top]=s[i]-k;
	q[++top]=0;q[++top]=k;
	sort(q+1,q+top+1);
	For(i,1,top)
		if(!mp[q[i]])	mp[q[i]]=++tot;
	nxt[0]=mp[k];
	For(i,1,n)
	{
		lst[i]=mp[s[i]-k];
		nxt[i]=mp[s[i]+k];	
		s[i]=mp[s[i]];
	}
	m=read();
	int block=sqrt(n);
	For(i,1,m)	que[i].L=read(),que[i].R=read(),que[i].num=i;
	For(i,1,m)	que[i].bl=que[i].L/block,que[i].br=que[i].R/block;
	sort(que+1,que+m+1,cmp);
	MO();
	sort(que+1,que+m+1,cmp1);
	For(i,1,m)	printf("%I64d\n",que[i].ans);
}